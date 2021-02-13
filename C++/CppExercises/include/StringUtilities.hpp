//
//  StringUtilities.hpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 8/14/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#pragma once

#include <cstdio>
//#include <iostream>
#include <string>
#include <vector>

class StringUtilities {
public:
  static std::string defangIPaddress(std::string address);
  static int numJewelsInStones(std::string J, std::string S);
  static std::string toLowerCase(std::string str);
  static std::vector<int> shortestToChar(std::string S, char C);
  static bool repeatedSubstringPattern(const std::string &s);
  static std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs);
  static bool parseCSV(const std::string &fileName);
};
