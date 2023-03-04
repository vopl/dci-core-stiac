/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "fixEndian.hpp"
#include <type_traits>

namespace dci::stiac::serialization
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T> concept Real = std::is_floating_point_v<T> && (4 == sizeof(T) || 8 == sizeof(T));

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <Real R>
    void save(auto& ar, const R& v)
    {
        R vFixed = fixEndian(v);
        ar.write(&vFixed, sizeof(vFixed));
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <Real R>
    void load(auto& ar, R& v)
    {
        R r;
        ar.read(&r, sizeof(v));
        v = fixEndian(r);
    }
}
