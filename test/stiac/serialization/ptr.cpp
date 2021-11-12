/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
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
TEST(stiac, ptr)
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    hereThere2( Ptr<char>({}),            [](const Ptr<char>&  , const Ptr<char>& b){EXPECT_FALSE(b);});
    hereThere2( Ptr<char>(new char('x')), [](const Ptr<char>& a, const Ptr<char>& b){EXPECT_EQ(*a, *b);});

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    {
        Ptr<char>   p1(new char('x'));
        Ptr<String> p2(new String("y"));
        Ptr<int>    p3(new int(220));
        hereThere2( Tuple{p1, p1, p2, p1, p2, p2, p3}, [](const auto& a, const auto& b)
        {
            EXPECT_EQ(*std::get<0>(a), *std::get<0>(b));
            EXPECT_EQ(*std::get<1>(a), *std::get<1>(b));
            EXPECT_EQ(*std::get<2>(a), *std::get<2>(b));
            EXPECT_EQ(*std::get<3>(a), *std::get<3>(b));
            EXPECT_EQ(*std::get<4>(a), *std::get<4>(b));
            EXPECT_EQ(*std::get<5>(a), *std::get<5>(b));
            EXPECT_EQ(*std::get<6>(a), *std::get<6>(b));

            EXPECT_EQ(std::get<0>(b), std::get<1>(b));
            EXPECT_EQ(std::get<0>(b), std::get<3>(b));

            EXPECT_EQ(std::get<2>(b), std::get<4>(b));
            EXPECT_EQ(std::get<2>(b), std::get<5>(b));
        });
    }
}
