/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
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
TEST(stiac, real)
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    hereThere2( real32(0)            ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32(1)            ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32(-1)           ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32(0.5)          ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32(-0.5)         ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32(-1.2345678)   ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32(-9.8765432)   ,[](auto a, auto b){EXPECT_EQ(a, b);});

    hereThere2( real32( std::numeric_limits<real32>::min())              ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32(-std::numeric_limits<real32>::min())              ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32( std::numeric_limits<real32>::lowest())           ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32(-std::numeric_limits<real32>::lowest())           ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32( std::numeric_limits<real32>::max())              ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32(-std::numeric_limits<real32>::max())              ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32( std::numeric_limits<real32>::epsilon())          ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32(-std::numeric_limits<real32>::epsilon())          ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32( std::numeric_limits<real32>::round_error())      ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32(-std::numeric_limits<real32>::round_error())      ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32( std::numeric_limits<real32>::infinity())         ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32(-std::numeric_limits<real32>::infinity())         ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real32( std::numeric_limits<real32>::quiet_NaN())        ,[](auto a, auto b){EXPECT_EQ(0, ::memcmp(&a, &b, sizeof(a)));});
    hereThere2( real32( std::numeric_limits<real32>::signaling_NaN())    ,[](auto a, auto b){EXPECT_EQ(0, ::memcmp(&a, &b, sizeof(a)));});
    hereThere2( real32( std::numeric_limits<real32>::denorm_min())       ,[](auto a, auto b){EXPECT_EQ(a, b);});

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    hereThere2( real64(0)            ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64(1)            ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64(-1)           ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64(0.5)          ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64(-0.5)         ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64(-1.2345678)   ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64(-9.8765432)   ,[](auto a, auto b){EXPECT_EQ(a, b);});

    hereThere2( real64( std::numeric_limits<real64>::min())              ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64(-std::numeric_limits<real64>::min())              ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64( std::numeric_limits<real64>::lowest())           ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64(-std::numeric_limits<real64>::lowest())           ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64( std::numeric_limits<real64>::max())              ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64(-std::numeric_limits<real64>::max())              ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64( std::numeric_limits<real64>::epsilon())          ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64(-std::numeric_limits<real64>::epsilon())          ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64( std::numeric_limits<real64>::round_error())      ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64(-std::numeric_limits<real64>::round_error())      ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64( std::numeric_limits<real64>::infinity())         ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64(-std::numeric_limits<real64>::infinity())         ,[](auto a, auto b){EXPECT_EQ(a, b);});
    hereThere2( real64( std::numeric_limits<real64>::quiet_NaN())        ,[](auto a, auto b){EXPECT_EQ(0, ::memcmp(&a, &b, sizeof(a)));});
    hereThere2( real64( std::numeric_limits<real64>::signaling_NaN())    ,[](auto a, auto b){EXPECT_EQ(0, ::memcmp(&a, &b, sizeof(a)));});
    hereThere2( real64( std::numeric_limits<real64>::denorm_min())       ,[](auto a, auto b){EXPECT_EQ(a, b);});
}
