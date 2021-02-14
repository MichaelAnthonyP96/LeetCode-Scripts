//
//  mathUtilTests.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 8/14/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "MathUtilities.h"
#include "catch.hpp"

TEST_CASE("isHappyTests", "numberProcessing") {
  REQUIRE(MathUtilities::isHappy(19) == true);
  REQUIRE(MathUtilities::isHappy(2) == false);
}

TEST_CASE("moveZeroesTest", "numberProcessing") {
  std::vector<int> input = {0,1,0,3,12};
  MathUtilities::moveZeroes(input);
  REQUIRE( input[0] == 1);
  REQUIRE( input[1] == 3);
  REQUIRE( input[2] == 12);
  REQUIRE( input[3] == 0);
  REQUIRE( input[4] == 0);

  std::vector<int> input2 = {0};
  MathUtilities::moveZeroes(input2);
  REQUIRE( input2[0] == 0);

  input2.push_back(0);
  MathUtilities::moveZeroes(input2);
  REQUIRE( input2[0] == 0);
  REQUIRE( input2[1] == 0);
}