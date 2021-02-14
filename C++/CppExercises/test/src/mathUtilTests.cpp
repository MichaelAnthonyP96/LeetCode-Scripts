//
//  mathUtilTests.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 8/14/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "MathUtilities.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(isHappyTests, numberProcessing) {
  EXPECT_EQ(MathUtilities::isHappy(19), true);
  EXPECT_EQ(MathUtilities::isHappy(2), false);
}

TEST(moveZeroesTest, numberProcessing) {
  std::vector<int> input = {0, 1, 0, 3, 12};
  MathUtilities::moveZeroes(input);
  EXPECT_EQ(input[0], 1);
  EXPECT_EQ(input[1], 3);
  EXPECT_EQ(input[2], 12);
  EXPECT_EQ(input[3], 0);
  EXPECT_EQ(input[4], 0);

  std::vector<int> input2 = {0};
  MathUtilities::moveZeroes(input2);
  EXPECT_EQ(input2[0], 0);

  input2.push_back(0);
  MathUtilities::moveZeroes(input2);
  EXPECT_EQ(input2[0], 0);
  EXPECT_EQ(input2[1], 0);
}