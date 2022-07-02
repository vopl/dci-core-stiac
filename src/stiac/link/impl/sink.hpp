/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/stiac/link/id.hpp>
#include <dci/stiac/link/base.hpp>
#include <dci/primitives.hpp>
#include <dci/bytes.hpp>
#include <map>

namespace dci::stiac::link
{
    class Hub4Sink;
}

namespace dci::stiac::link::impl
{
    class Sink final
    {

    public:
        Sink(Hub4Sink* hub, bytes::Alter&& dataAlter, bool doFinalization);
        Sink(Sink&& from);
        ~Sink();

        Hub4Sink* context();

        void write(const void* data, uint32 size);
        void write(Bytes&& data);

        std::pair<uint32, bool> mapTuid(const std::array<uint8, 16>& tuid);

        std::pair<uint32, bool> pushPtr(void* ptrMark);

        void finalize();

        void fail(const char* cszDetails);

        LocalId emplaceLink(BasePtr&& link);

    private:
        Hub4Sink *                  _hub;

        bytes::Alter                _dataAlter;
        bool                        _doFinalization;
        bool                        _finalized;

        std::map<void *, uint32>    _ptrShareContext;
    };
}
