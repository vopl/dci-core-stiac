/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/exception.hpp>
#include <dci/idl/introspection.hpp>

namespace dci::stiac::serialization
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class T> concept Exception = std::is_base_of_v<dci::Exception, T>;

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <Exception T>
    void save(auto& ar, const T& v)
    {
        ar << v.whatBuffer();

        if constexpr(idl::introspection::isException<T>)
        {
            idl::introspection::applyBases([&](const auto&... v)
            {
                (void)(ar << ... << v);
            }, v);

            idl::introspection::applyFields([&](const auto&... v)
            {
                (void)(ar << ... << v);
            }, v);
        }
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <Exception T>
    void save(auto& ar, T&& v)
    {
        ar << std::move(v.whatBuffer());

        if constexpr(idl::introspection::isException<T>)
        {
            idl::introspection::applyBases([&](auto&&... v)
            {
                (void)(ar << ... << std::move(v));
            }, std::move(v));

            idl::introspection::applyFields([&](auto&&... v)
            {
                (void)(ar << ... << std::move(v));
            }, std::move(v));
        }
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <Exception T>
    void load(auto& ar, T& v)
    {
        ar >> v.whatBuffer();

        if constexpr(idl::introspection::isException<T>)
        {
            idl::introspection::applyBases([&](auto&... v)
            {
                (void)(ar >> ... >> v);
            }, v);

            idl::introspection::applyFields([&](auto&... v)
            {
                (void)(ar >> ... >> v);
            }, v);
        }
    }
}
