/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "api.hpp"
#include <dci/exception.hpp>
#include <dci/stiac/link/sink.hpp>
#include <dci/stiac/link/source.hpp>

namespace dci::stiac
{
    class API_DCI_STIAC ExceptionSerializersRegistry
    {
    public:
        using Saver = void(*)(link::Sink&, const dci::Exception*);
        using Loader = void(*)(link::Source&, dci::Exception*);

        Saver getSaver(const Eid&);
        Loader getLoader(const Eid&);

    public:
        bool registrate(const char* name, const Eid&, Saver, Loader);
    };

    extern ExceptionSerializersRegistry& exceptionSerializersRegistry API_DCI_STIAC;
}
