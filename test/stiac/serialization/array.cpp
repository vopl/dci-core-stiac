/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include <dci/test.hpp>
#include "utils/hereThere.hpp"
using namespace utils;

#include <dci/primitives.hpp>

using namespace dci;

/////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
TEST(stiac, array)
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    hereThere2( Array<int, 0>({})                    ,[](const auto& a, const auto& b){EXPECT_EQ(a, b);});
    hereThere2( Array<char, 2>({'a', 'b'})           ,[](const auto& a, const auto& b){EXPECT_EQ(a, b);});
    hereThere2( Array<String, 3>({"asd", "fg", "h"}) ,[](const auto& a, const auto& b){EXPECT_EQ(a, b);});
}
