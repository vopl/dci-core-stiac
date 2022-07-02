/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <variant>
#include <dci/primitives.hpp>
#include "../smallIntegral.hpp"

namespace dci::stiac::serialization
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class... Ts>
    void save(auto& ar, const std::variant<Ts...>& v)
    {
        if(std::variant_npos == v.index())
        {
            ar << smallIntegral(uint32{0});
            return;
        }

        ar << smallIntegral(static_cast<uint32>(v.index())+1);

        std::visit([&](const auto& v)
        {
            ar << v;
        }, v);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class... Ts>
    void save(auto& ar, std::variant<Ts...>&& v)
    {
        if(std::variant_npos == v.index())
        {
            ar << smallIntegral(uint32{0});
            return;
        }

        ar << smallIntegral(static_cast<uint32>(v.index())+1);

        std::visit([&](auto&& v)
        {
            ar << std::move(v);
        }, std::move(v));
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    namespace details
    {
        struct BadVariantMaker
        {
            struct Exception {};

            template <class Any>
            operator Any() const
            {
                throw Exception();
            }
        };

        template <std::size_t currentIndex, class... T>
        void loadVariantMember(auto& ar, std::size_t wantedIndex, std::variant<T...>& v)
        {
            if(wantedIndex == currentIndex)
            {
                std::variant_alternative_t<currentIndex, std::variant<T...>> member;
                ar >> member;
                v.template emplace<currentIndex>(std::move(member));
                return;
            }

            if constexpr(currentIndex+1 < sizeof...(T))
            {
                loadVariantMember<currentIndex+1, T...>(ar, wantedIndex, v);
                return;
            }
            else
            {
                throw "malformed input";
            }
        }
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class... Ts>
    void load(auto& ar, std::variant<Ts...>& v)
    {
        uint32 index;
        ar >> smallIntegral(index);

        if(!index)
        {
            try
            {
                v.template emplace<0>(details::BadVariantMaker());
            }
            catch(details::BadVariantMaker::Exception)
            {
                //ignore
            }
            return;
        }

        details::loadVariantMember<0, Ts...>(ar, index-1, v);
    }
}
