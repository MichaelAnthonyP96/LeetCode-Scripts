//
//  arrayUtilTests.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 8/14/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "ArrayUtilities.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(profitTests, Max) {
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  EXPECT_EQ(ArrayUtilities::maxProfit(prices), 7);

  std::vector<int> prices2 = {1, 2, 3, 4, 5};
  EXPECT_EQ(ArrayUtilities::maxProfit(prices2), 4);

  std::vector<int> prices3 = {7, 6, 4, 3, 1};
  EXPECT_EQ(ArrayUtilities::maxProfit(prices3), 0);

  std::vector<int> prices4 = {2, 1, 4, 5, 2, 9, 7};
  EXPECT_EQ(ArrayUtilities::maxProfit(prices4), 11);
}

TEST(mergeSort, Ascending) {
  std::vector<int> nums = {5, 2, 3, 1, 4};
  std::vector<int> result = ArrayUtilities::sortArray(nums);
  EXPECT_EQ(result[0], 1);
  EXPECT_EQ(result[1], 2);
  EXPECT_EQ(result[2], 3);
  EXPECT_EQ(result[3], 4);
  EXPECT_EQ(result[4],  5);

  nums = {5, 1, 1, 2, 0, 0};
  result = ArrayUtilities::sortArray(nums);
  EXPECT_EQ(result[0], 0);
  EXPECT_EQ(result[1], 0);
  EXPECT_EQ(result[2], 1);
  EXPECT_EQ(result[3], 1);
  EXPECT_EQ(result[4], 2);
  EXPECT_EQ(result[5], 5);

}

TEST(ArthimeticProgress, Sequence) {
  std::vector<int> nums = {5, 2, 3, 1, 4};
  EXPECT_TRUE(ArrayUtilities::canMakeArithmeticProgression(nums));

  std::vector<int> nums2 = {3, 5, 1};
  EXPECT_TRUE(ArrayUtilities::canMakeArithmeticProgression(nums2));
}

//TEST_CASE("mergeSort", "") {
//  std::vector<int> nums = {5, 1, 1, 2, 0, 0};
//  std::vector<int> result = ArrayUtilities::sortArray(nums);
//  EXPECT_EQ(result[0], 0);
//  EXPECT_EQ(result[1], 0);
//  EXPECT_EQ(result[2], 1);
//  EXPECT_EQ(result[3], 1);
//  EXPECT_EQ(result[4], 2);
//  EXPECT_EQ(result[5], 5);
//}