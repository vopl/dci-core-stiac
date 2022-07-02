/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/cmt/future.hpp>
#include "../future.hpp"

namespace dci::stiac::link::serialization
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T>
    void save(auto& ar, const cmt::Future<T>& v)
    {
        dbgAssert(v.charged());
        ar << ar.emplaceLink(new Impl<cmt::Future<T>>{v});
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T>
    void save(auto& ar, cmt::Future<T>&& v)
    {
        dbgAssert(v.charged());
        ar << ar.emplaceLink(new Impl<cmt::Future<T>>{std::move(v)});
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T>
    void load(auto& ar, const cmt::Future<T>& v)
    {
        dbgAssert(v.charged());

        RemoteId remoteId;
        ar >> remoteId;

        if(!ar.emplaceLink(BasePtr(new Impl<cmt::Future<T>>{v}), remoteId))
        {
            ar.fail("bad link");
        }
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T>
    void load(auto& ar, cmt::Future<T>&& v)
    {
        dbgAssert(v.charged());

        RemoteId remoteId;
        ar >> remoteId;

        if(!ar.emplaceLink(BasePtr(new Impl<cmt::Future<T>>{std::move(v)}), remoteId))
        {
            ar.fail("bad link");
        }
    }

}
