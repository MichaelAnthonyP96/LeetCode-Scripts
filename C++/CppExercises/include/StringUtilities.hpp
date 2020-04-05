//
//  StringUtilities.hpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 8/14/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#ifndef StringUtilities_hpp
#define StringUtilities_hpp

#include <stdio.h>
//#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StringUtilities {
public:
  static string defangIPaddr(string address);
  static int numJewelsInStones(string J, string S);
  static string toLowerCase(string str);
  static std::vector<int> shortestToChar(std::string S, char C);
  static bool repeatedSubstringPattern(string s);
};

#endif // StringUtilities_hpp
