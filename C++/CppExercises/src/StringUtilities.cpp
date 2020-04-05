//
//  StringUtilities.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 8/14/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "StringUtilities.hpp"
#include <iostream>

// TODO(mapope): add tests for stringUtil methods
// TODO(mapope): add doxygen to all stringUtil methods
// Given a valid (IPv4) IP address, return a defanged version of that IP
// address. A defanged IP address replaces every period "." with "[.]".
string StringUtilities::defangIPaddr(string address) {
  size_t f = 0;
  int place = 0;
  do {
    f = address.substr(place, address.length() - place).find(".");
    if (f != std::string::npos) {
      address.insert(f + place, "[");
      address.insert(f + place + 2, "]");
      place = place + f + 2;
    }

  } while (f != std::string::npos);
  return address;
}

// You're given strings J representing the types of stones that are jewels, and
// S representing the stones you have. Each character in S is a type of stone
// you have.  You want to know how many of the stones you have are also jewels.
// The letters in J are guaranteed distinct, and all characters in J and S are
// letters. Letters are case sensitive, so "a" is considered a different type of
// stone from "A".
int StringUtilities::numJewelsInStones(string J, string S) {
  std::string::iterator it = S.begin();
  int ret = 0;
  while (it != S.end()) {
    if (J.find(*it) != std::string::npos) {
      ++ret;
    }
    ++it;
  }
  return ret;
}

// Implement function ToLowerCase() that has a string parameter str, and returns
// the same string in lowercase.
string StringUtilities::toLowerCase(string str) {
  std::string s;
  for (int i = 0; i < str.length(); ++i) {
    s.insert(s.end(), std::tolower(str[i]));
  }
  return s;
}

// Given a string S and a character C, return an array of integers representing
// the shortest distance from the character C in the string.
std::vector<int> StringUtilities::shortestToChar(std::string S, char C) {
  std::vector<int> ret(S.length(), INT_MAX);

  for (int i = 0; i < S.length(); ++i) {
    if (S[i] == C) {
      ret[i] = 0;
      // update left of the found char
      for (int j = i - 1; j >= 0; --j) {
        if (S[j] == C) {
          // we found another match, stop searching left
          break;
        }
        if (ret[j] > ret[j + 1]) {
          // update the values to the left
          ret[j] = ret[j + 1] + 1;
        } else { // if the value is equal to or less than, no need to
                 // continue updating
          break;
        }
      }
      // update right of the found char
      for (int k = i + 1; k < S.length(); ++k) {
        if (S[k] == C) {
          // we found another match, stop searching right. Advance i to that
          // position
          ret[k] = 0;
          i = k - 1; // ++ operator will bring i to position k at next loop
                     // iteration
          break;
        }
        if (ret[k] > ret[k - 1]) {
          // update the values to the left
          ret[k] = ret[k - 1] + 1;
        }
      }
    }
  }
  return ret;
}
/**
 * \brief Determine if a string can be constructed by taking a substring.
 *
 * Given a non-empty string check if it can be constructed by taking a substring
 * of it and appending multiple copies of the substring together. You may assume
 * the given string consists of lowercase English letters only and its length
 * will not exceed 10000.
 *
 * \param s String to examine
 * \return true or false whether a valid substring exists
 */
bool StringUtilities::repeatedSubstringPattern(string s) {
  int subLength = 1;
  string substr, compare;
  while (subLength <= s.length()) {
    if (subLength > (s.length() / 2)) {
      return false;
    }
    substr = s.substr(0, subLength);
    compare = s.substr(subLength, s.length() - subLength);
    if (compare.find(substr) != string::npos) {
      if (s.length() % subLength != 0) {
        ++subLength;
        continue;
      }
      int multiplier = s.length() / subLength;
      compare = substr;
      for (int i = 1; i < multiplier; ++i) {
        compare += substr;
      }
      if (compare == s) {
        return true;
      }
    }
    ++subLength;
  }
  return false;
}