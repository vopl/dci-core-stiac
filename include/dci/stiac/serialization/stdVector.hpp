/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/primitives.hpp>
#include "../smallIntegral.hpp"
#include <vector>

namespace dci::stiac::serialization
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T>
    void save(auto& ar, const std::vector<T>& v)
    {
        ar << smallIntegral(static_cast<uint32>(v.size()));

        for(const T& e : v)
        {
            ar << e;
        }
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T>
    void save(auto& ar, std::vector<T>&& v)
    {
        ar << smallIntegral(static_cast<uint32>(v.size()));

        for(T& e : v)
        {
            ar << std::move(e);
        }
        v.clear();
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T>
    void load(auto& ar, std::vector<T>& v)
    {
        uint32 size;
        ar >> smallIntegral(size);

        if(size * 1 > ar.size())
        {
            ar.fail("malformed input stream (low data)");
        }

        v.resize(size);

        for(std::size_t i(0); i<v.size(); ++i)
        {
            ar >> v[i];
        }
    }
}
