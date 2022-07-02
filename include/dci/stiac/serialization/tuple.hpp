/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/primitives.hpp>

namespace dci::stiac::serialization
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class... Ts> void save(auto& ar, const Tuple<Ts...>& v)
    {
        v.apply([&](const auto&... v)
        {
            (void)(ar << ... << v);
        });
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class... Ts> void save(auto& ar, Tuple<Ts...>&& v)
    {
        std::move(v).apply([&](auto&&... v)
        {
            (void)(ar << ... << std::move(v));
        });
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class... Ts> void load(auto& ar, Tuple<Ts...>& v)
    {
        v.apply([&](auto&... v)
        {
            (void)(ar >> ... >> v);
        });
    }
}
