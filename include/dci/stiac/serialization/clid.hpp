/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/idl/contract/lid.hpp>
#include <dci/idl/contract/id.hpp>
#include <dci/idl/contract/lidRegistry.hpp>
#include <dci/logger.hpp>

namespace dci::stiac::serialization
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void save(auto& ar, const idl::contract::Lid& v)
    {
        ar << idl::contract::lidRegistry.get(v);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    void load(auto& ar, idl::contract::Lid& v)
    {
        idl::contract::Id id;
        ar >> id;
        v = idl::contract::lidRegistry.get(id);

        if(!v)
        {
            //ar.fail((std::string{"unknown contract id provided: "} + id.toHex()).data());
            LOGI("unknown contract id provided: " << id.toHex() << ", memorized");
            v = idl::contract::lidRegistry.emplace(id);
        }
    }
}
