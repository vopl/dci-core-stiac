/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/utils/bits.hpp>
#include "../smallIntegral.hpp"
#include "fixEndian.hpp"

namespace dci::stiac::serialization
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T> concept SmallIntegralSigned = T::_isSmallIntegral && T::_isSigned;

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <SmallIntegralSigned T>
    void save(auto& ar, const T& v)
    {
        static_assert(sizeof(v)<=8);

        if constexpr(1 == sizeof(v))
        {
            ar.write(&v._v, 1);
            return;
        }

        if constexpr(2 == sizeof(v))
        {
            typename T::V vFixed = fixEndian(v._v);
            ar.write(&vFixed, 2);
            return;
        }

        if constexpr(4 <= sizeof(v))
        {
            using U = std::make_unsigned_t<typename T::V>;

            U vZigZag = static_cast<U>((v._v << 1) ^ (v._v >> (utils::bits::bitsof(v._v)-1)));
            ar << SmallIntegral<U>{vZigZag};
        }
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <SmallIntegralSigned T>
    void load(auto& ar, T& v)
    {
        static_assert(sizeof(v)<=8);

        if constexpr(1 == sizeof(v))
        {
            ar.read(&v, 1);
            return;
        }

        if constexpr(2 == sizeof(v))
        {
            typename T::V s;
            ar.read(&s, 2);
            v._v = fixEndian(s);
            return;
        }

        if constexpr(4 <= sizeof(v))
        {
            using U = std::make_unsigned_t<typename T::V>;
            SmallIntegral<U> vZigZag;
            ar >> vZigZag;

            v._v = static_cast<typename T::V>((vZigZag._v >> 1)) ^ -static_cast<typename T::V>(vZigZag._v & 1);
        }
    }
}
