//
//  MathUtilities.hpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#ifndef MathUtilities_h
#define MathUtilities_h

#include <stdio.h>
#include <string>

using namespace std;

class MathUtilities{
public:
    static int mySqrt(int x);
    static int climbStairs(int n);
    static std::string addBinary(std::string a, std::string b);
    static void rotate(std::vector<int>& nums, int k);
    static int singleNumber(vector<int>& nums);
};

#endif /* MathUtilities_hpp */
