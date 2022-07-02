/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/primitives.hpp>
#include "fixEndian.hpp"
#include <type_traits>

namespace dci::stiac::serialization
{
    template <class T> concept Integral = std::is_integral_v<T>;

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <Integral I>
    void save(auto& ar, const I& v)
    {
        static_assert(sizeof(v)<=8);

        I vFixed = fixEndian(v);
        ar.write(&vFixed, sizeof(vFixed));
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <Integral I>
    void load(auto& ar, I& v)
    {
        static_assert(sizeof(v)<=8);

        I vUnfixed;
        ar.read(&vUnfixed, sizeof(vUnfixed));
        v = fixEndian(vUnfixed);
    }
}
