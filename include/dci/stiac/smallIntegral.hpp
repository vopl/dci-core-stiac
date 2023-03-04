/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <type_traits>

namespace dci::stiac
{
    template <class T> requires std::is_integral_v<T>
    struct SmallIntegral
    {
        static constexpr bool _isSmallIntegral = true;
        static constexpr bool _isSigned = std::is_signed_v<T>;
        static constexpr bool _isUnsigned = std::is_unsigned_v<T>;

        using V = T;
        V _v;
    };

    template <class T> requires std::is_integral_v<T>
    const SmallIntegral<T>& smallIntegral(const T& v)
    {
        static_assert(sizeof(T) == sizeof(SmallIntegral<T>));
        static_assert(alignof(T) == alignof(SmallIntegral<T>));

        return *static_cast<const SmallIntegral<T>*>(static_cast<const void*>(&v));
    }

    template <class T> requires std::is_integral_v<T>
    SmallIntegral<T>& smallIntegral(T& v)
    {
        static_assert(sizeof(T) == sizeof(SmallIntegral<T>));
        static_assert(alignof(T) == alignof(SmallIntegral<T>));

        return *static_cast<SmallIntegral<T>*>(static_cast<void*>(&v));
    }

    template <class T> requires std::is_integral_v<T>
    SmallIntegral<T>&& smallIntegral(T&& v)
    {
        static_assert(sizeof(T) == sizeof(SmallIntegral<T>));
        static_assert(alignof(T) == alignof(SmallIntegral<T>));

        return std::move(*static_cast<SmallIntegral<T>*>(static_cast<void*>(&v)));
    }
}
