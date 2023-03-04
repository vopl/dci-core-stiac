/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "arch.hpp"
#include "../serialization.hpp"

namespace dci::stiac::serialization
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline Arch::Arch(const bytes::Alter& from)
        : bytes::Alter(from)
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline Arch::Arch(bytes::Alter&& from)
        : bytes::Alter(std::move(from))
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline void Arch::read(void* data, uint32 size)
    {
        if(size != bytes::Alter::read(data, size))
        {
            fail("low data");
        }
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline void Arch::read(Bytes& data, uint32 size)
    {
        if(size != bytes::Alter::read(data, size))
        {
            fail("low data");
        }
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    [[noreturn]] inline void Arch::fail(const char* cszDetails)
    {
        throw std::runtime_error(cszDetails);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    inline Arch& Arch::operator<<(auto&& v)
    {
        using stiac::serialization::save;

        save(*this, std::forward<decltype(v)>(v));
        return *this;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    Arch& Arch::operator>>(auto&& v)
    {
        using stiac::serialization::load;

        load(*this, std::forward<decltype(v)>(v));
        return *this;
    }

}
