#include "ArrayUtilities.h"
#include "catch.hpp"

TEST_CASE("profitTests", "") {
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  REQUIRE(ArrayUtilities::maxProfit(prices) == 7);

  std::vector<int> prices2 = {1, 2, 3, 4, 5};
  REQUIRE(ArrayUtilities::maxProfit(prices2) == 4);

  std::vector<int> prices3 = {7, 6, 4, 3, 1};
  REQUIRE(ArrayUtilities::maxProfit(prices3) == 0);

  std::vector<int> prices4 = {2, 1, 4, 5, 2, 9, 7};
  REQUIRE(ArrayUtilities::maxProfit(prices4) == 11);
}
