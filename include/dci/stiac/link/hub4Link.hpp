/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "id.hpp"

namespace dci::stiac::link
{
    class Sink;

    class Hub4Link
    {
    public:
        virtual ~Hub4Link() = default;
        virtual Sink makeSink(Id id) = 0;

        enum UninvolvingFlags
        {
            uf_beginRemove  = 0x001,
            uf_endRemove    = 0x002,
            uf_remove       = 0x004,

            uf_sendBegin    = 0x010,
            uf_sendEnd      = 0x020,
        };

        virtual void linkUninvolved(Id id, int uf/* = uf_beginRemove | uf_sendBegin*/) = 0;
    };
}
