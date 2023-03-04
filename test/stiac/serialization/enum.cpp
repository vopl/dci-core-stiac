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
TEST(stiac, enum)
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    // enum class
    {
        enum E1 { x,y,z };

        hereThere2( x            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( y            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( z            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum E1 : uint8 { x,y,z };

        hereThere2( x            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( y            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( z            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum E1 : uint16 { x,y,z };

        hereThere2( x            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( y            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( z            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum E1 : uint32 { x,y,z };

        hereThere2( x            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( y            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( z            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum E1 : uint64 { x,y,z };

        hereThere2( x            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( y            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( z            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum E1 : uint8 { x,y,z };

        hereThere2( x            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( y            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( z            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum E1 : int16 { x,y,z };

        hereThere2( x            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( y            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( z            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum E1 : int32 { x,y,z };

        hereThere2( x            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( y            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( z            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum E1 : int64 { x,y,z };

        hereThere2( x            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( y            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( z            ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    // enum class
    {
        enum class E1 { x,y,z };

        hereThere2( E1::x        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::y        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::z        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum class E1 : uint8 { x,y,z };

        hereThere2( E1::x        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::y        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::z        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum class E1 : uint16 { x,y,z };

        hereThere2( E1::x        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::y        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::z        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum class E1 : uint32 { x,y,z };

        hereThere2( E1::x        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::y        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::z        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum class E1 : uint64 { x,y,z };

        hereThere2( E1::x        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::y        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::z        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum class E1 : uint8 { x,y,z };

        hereThere2( E1::x        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::y        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::z        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum class E1 : int16 { x,y,z };

        hereThere2( E1::x        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::y        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::z        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum class E1 : int32 { x,y,z };

        hereThere2( E1::x        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::y        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::z        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }

    {
        enum class E1 : int64 { x,y,z };

        hereThere2( E1::x        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::y        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1::z        ,[](auto a, auto b){EXPECT_EQ(a, b);});
        hereThere2( E1(17)       ,[](auto a, auto b){EXPECT_EQ(a, b);});
    }


}
