//
//  arrayUtilTests.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 8/14/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

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

TEST_CASE("mergeSort", "Ascending") {
  std::vector<int> nums = {5, 2, 3, 1, 4};
  std::vector<int> result = ArrayUtilities::sortArray(nums);
  REQUIRE(result[0] == 1);
  REQUIRE(result[1] == 2);
  REQUIRE(result[2] == 3);
  REQUIRE(result[3] == 4);
  REQUIRE(result[4] == 5);

  nums = {5, 1, 1, 2, 0, 0};
  result = ArrayUtilities::sortArray(nums);
  REQUIRE(result[0] == 0);
  REQUIRE(result[1] == 0);
  REQUIRE(result[2] == 1);
  REQUIRE(result[3] == 1);
  REQUIRE(result[4] == 2);
  REQUIRE(result[5] == 5);

}

TEST_CASE("Arthimetic Progress", "Sequence") {
  std::vector<int> nums = {5, 2, 3, 1, 4};
  REQUIRE(ArrayUtilities::canMakeArithmeticProgression(nums));

  std::vector<int> nums2 = {3, 5, 1};
  REQUIRE(ArrayUtilities::canMakeArithmeticProgression(nums2));
}

//TEST_CASE("mergeSort", "") {
//  std::vector<int> nums = {5, 1, 1, 2, 0, 0};
//  std::vector<int> result = ArrayUtilities::sortArray(nums);
//  REQUIRE(result[0] == 0);
//  REQUIRE(result[1] == 0);
//  REQUIRE(result[2] == 1);
//  REQUIRE(result[3] == 1);
//  REQUIRE(result[4] == 2);
//  REQUIRE(result[5] == 5);
//}
