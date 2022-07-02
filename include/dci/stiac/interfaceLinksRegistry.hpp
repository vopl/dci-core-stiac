/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "api.hpp"
#include "link/base.hpp"
#include <dci/idl/interface.hpp>
#include <dci/idl/interface/lid.hpp>

namespace dci::stiac
{
    class API_DCI_STIAC InterfaceLinksRegistry
    {
    public:
        using Factory1 = link::BasePtr(*)(idl::Interface&& interface);
        using Factory2 = link::BasePtr(*)(idl::Interface& interface);

        link::BasePtr create1(const idl::interface::Lid& lid, idl::Interface&& interface);
        link::BasePtr create2(const idl::interface::Lid& lid, idl::Interface& interface);

    public:
        bool registrate(const char* name, const idl::interface::Lid& lid, Factory1 factory1, Factory2 factory2);
    };

    extern InterfaceLinksRegistry& interfaceLinksRegistry API_DCI_STIAC;
}
