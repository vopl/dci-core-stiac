/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/bytes.hpp>

namespace dci::stiac::serialization
{
    struct Arch
        : bytes::Alter
    {
        using bytes::Alter::Alter;
        Arch() = delete;
        Arch(const bytes::Alter& from);
        Arch(bytes::Alter&& from);

        void read(void* data, uint32 size);
        void read(Bytes& data, uint32 size);

        [[noreturn]] void fail(const char* cszDetails);

        Arch& operator<<(auto&& v);
        Arch& operator>>(auto&& v);
    };

}
