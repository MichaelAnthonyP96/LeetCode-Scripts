#include "StringUtilities.hpp"
#include "catch.hpp"

TEST_CASE("SchedulerTests", "DisjointActions") {
  std::vector<int> expected = {3,2,1,0,1,0,0,1,2,2,1,0};
  REQUIRE(StringUtilities::shortestToChar("loveleetcode", 'e') == expected);
}