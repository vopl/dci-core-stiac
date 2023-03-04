/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/primitives.hpp>
#include <dci/bytes.hpp>
#include "id.hpp"
#include "base.hpp"

namespace dci::stiac::link
{
    class Sink;

    class Hub4Sink
    {
    public:
        virtual ~Hub4Sink() = default;

        virtual LocalId emplaceLink(BasePtr&& link) = 0;
        virtual void finalize(Sink& sink, bytes::Alter&& buffer) = 0;
        virtual std::pair<uint32, bool> mapTuid(const std::array<uint8, 16>& tuid) = 0;
    };

}
