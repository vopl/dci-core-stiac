/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "future.hpp"
#include "sink.hpp"
#include "source.hpp"
#include "methodId.hpp"

namespace dci::stiac::link
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T>
    Impl<cmt::Future<T>>::Impl(cmt::Future<T>&& future)
        : _future(std::move(future))
    {
        dbgAssert(_future.charged());
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T>
     Impl<cmt::Future<T>>:: Impl(const cmt::Future<T>& future)
        : _future(future)
    {
        dbgAssert(_future.charged());
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T>
    void  Impl<cmt::Future<T>>::initialize(Hub4Link* hub, Id id)
    {
        Base::initialize(hub, id);

        _future.then() += _sbsOwner * [&](cmt::Future<T>& future)
        {
            _sbsOwner.flush();

            if(!_hub)
            {
                return;
            }

            Sink sink = _hub->makeSink(_id);
            _hub->linkUninvolved(_id, Hub4Link::uf_beginRemove);

            dbgAssert(future.resolved());

            if(future.resolvedValue())
            {
                sink << MethodId(0);

                if constexpr(!std::is_same_v<void, T>)
                {
                    sink << future.detachValue();
                }
            }
            else if(future.resolvedException())
            {
                sink << MethodId(1);
                sink << future.detachException();
            }
            else // if(future.resolvedCancel())
            {
                sink << MethodId(2);
            }

            sink.finalize();
        };
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T>
    void  Impl<cmt::Future<T>>::input(Source& source)
    {
        _sbsOwner.flush();

        if(!_hub)
        {
            return;
        }

        cmt::Future<T> future(std::move(_future));
        dbgAssert(future.charged());

        _hub->linkUninvolved(_id, Hub4Link::uf_remove | Hub4Link::uf_endRemove | Hub4Link::uf_sendEnd);

        bool canResolve = future.charged() && !future.resolved();

        MethodId methodId;
        source >> methodId;

        switch(static_cast<std::underlying_type_t<MethodId>>(methodId))
        {
        case 0://cancel
            source.finalize();

            if(canResolve)
            {
                future.resolveCancel();
            }
            break;

        default:
            source.fail("malformed input");
            return;
        }
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T>
    void  Impl<cmt::Future<T>>::destroy()
    {
        _sbsOwner.flush();

        if(_future.charged() && !_future.resolved())
        {
            _future.resolveCancel();
        }

        delete this;
    }

}
