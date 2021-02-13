//
//  StringUtilities.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 8/14/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "StringUtilities.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

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
    // if the substring is not an integer multiple of the original length,
    // then it is not a valid length
    if (s.length() % subLength != 0) {
      ++subLength;
      continue;
    }
    // a valid substring cannot be more than half the original string
    if (subLength > (s.length() / 2)) {
      return false;
    }
    substr = s.substr(0, subLength);
    compare = s.substr(subLength, s.length() - subLength);
    if (compare.find(substr) != string::npos) {
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

/**
 * \brief Given an array of strings, group the anagrams together. An Anagram is
 * a word or phrase formed by rearranging the letters of a different word or
 * phrase, typically using all the original letters exactly once.
 *
 * LeetCode problem 49
 * \param strings A vector of input strings
 * \return A vector of vectors of grouped anagrams
 */
std::vector<std::vector<std::string>>
StringUtilities::groupAnagrams(std::vector<std::string> &strings) {
  std::vector<std::vector<std::string>> wordGroups;
  std::vector<std::pair<std::string, std::map<char, int>>> hashes;
  std::map<std::string, int> sets;
  // build hashes counting each letter instance in each word
  int anagramCounter = 0;
  for (auto &&currStr : strings) {
    // check for duplicate words
    auto duplicate = sets.find(currStr);
    if (duplicate != sets.end()) {
      // if a duplicate is found, add it to the anagram set and continue
      // processing
      wordGroups[duplicate->second].push_back(currStr);
      continue;
    }

    // handle the empty string case
    if (currStr.empty()) {
      auto find = sets.find(currStr);
      if (find != sets.end()) {
        wordGroups[find->second].push_back(currStr);
      } else {
        std::vector<std::string> tempVec = {currStr};
        wordGroups.push_back(tempVec);
        sets.insert(std::pair<std::string, int>(currStr, anagramCounter++));
      }
      continue;
    }

    // hash the current string
    std::map<char, int> tempMap;
    for (char &i : currStr) {
      auto it = tempMap.find(i);
      if (it == tempMap.end()) {
        tempMap.insert(std::pair<char, int>(i, 1));
      } else {
        it->second += 1;
      }
    }

    // search over the anagram hashes
    bool anagramFound = false;
    for (auto &&anagramItr : hashes) {
      if (anagramItr.first.size() != currStr.size()) {
        continue;
      }
      bool nonMatch = false;
      for (auto &&currWordItr : tempMap) {
        auto search = anagramItr.second.find(currWordItr.first);
        if (search == anagramItr.second.end() ||
            search->second != currWordItr.second) {
          // letter counts don't match, move onto the next anagram hash
          nonMatch = true;
          break;
        }
      }
      if (!nonMatch) {
        // insert the currWord in the found anagram set
        auto found = sets.find(anagramItr.first);
        int set = 0;
        if (found != sets.end()) {
          set = found->second;
        } else {
          throw;
        }
        wordGroups[set].push_back(currStr);
        anagramFound = true;
        break;
      }
    }

    // prepare the base case
    if (!anagramFound) {
      hashes.emplace_back(currStr, tempMap);
      std::vector<std::string> tempVec = {currStr};
      wordGroups.push_back(tempVec);
      sets.insert(std::pair<std::string, int>(currStr, anagramCounter++));
      continue;
    }
  }

  return wordGroups;
}

/**
 * \brief
 * \param fileName
 * \return
 */
bool StringUtilities::parseCSV(const std::string &fileName) {

  // database to store data-in
  std::vector<std::vector<int>> db;

  // throw away the first line
  std::string tmp;
  std::getline(std::cin, tmp);
  // build up database using input from stdin
  while (std::getline(std::cin, tmp)) {
    int jobID = 0, runtime = 0, nextJobID = 0;
    std::istringstream is(tmp);
    char throwAway; // discard the ',' character
    is >> jobID;
    is >> throwAway;
    if (throwAway != ',') {
      std::cout << "Malformed Input" << std::endl;
      return false;
    }
    is >> runtime;
    is >> throwAway;
    if (throwAway != ',') {
      std::cout << "Malformed Input" << std::endl;
      return false;
    }
    is >> nextJobID;
    if ((jobID == 0) && (runtime == 0) && (nextJobID == 0)) {
      // it is likely that the current line being processed is not in CSV format
      std::cout << "Malformed Input" << std::endl;
      return false;
    }
    db.push_back(std::vector<int>{jobID, runtime, nextJobID, 1});
  }

  // if the db has size 0, something went really wrong when input processing
  if (db.empty()) {
    std::cout << "Malformed Input" << std::endl;
    return false;
  }

  // iterate over the DB and consolidate jobs
  for (auto i = 0; i < db.size(); ++i) {
    // using range based for loop gets confused when I remove the vectors
    auto &itr = db[i];
    int nextJobID = itr[2];
    for (auto &itr2 : db) {
      // if the current jobID matches a nextJobID, we combine these two vectors
      if (itr2[0] == nextJobID) {
        // combine the runtime
        itr[1] += itr2[1];
        // combine the total number of jobs
        itr[3] += itr2[3];
        // if the combined job isn't the last one in the chain, store the next
        // jobID
        if (itr2[2] != 0) {
          itr[2] = itr2[2];
        }
        // remove the job that has been combined
        db.erase(std::remove_if(
                     db.begin(), db.end(),
                     [itr2](const std::vector<int> &v) { return itr2 == v; }),
                 db.end());
      }
    }
  }

  // Sort the DB based on total runtime after all jobs have been consolidated
  // into chains
  // std::sort(db.begin(), db.end(), mySort);

  // print out info to stdout stream, assuming the input "time" is in seconds
  std::cout << "-" << std::endl;
  for (auto &currChain : db) {
    std::cout << "start_job: " << currChain[0] << std::endl;
    std::cout << "last_job: " << currChain[2] << std::endl;
    std::cout << "number_of_jobs: " << currChain[3] << std::endl;

    // Assuming the time input was in seconds
    int totalTime = currChain[1];
    int hours = totalTime / 360;
    int minutes = (totalTime - (hours * 360)) / 60;
    int seconds = (totalTime - (hours * 360) - (minutes * 60)) % 60;

    std::cout << "job_chain_runtime: " << std::setfill('0') << std::setw(2)
              << hours << ":" << std::setfill('0') << std::setw(2) << minutes
              << ":" << std::setfill('0') << std::setw(2) << seconds
              << std::endl;

    // round-off error using ints will certainly not be accurate, more logic is
    // needed here using doubles and accounting for fractions of an hour,
    // minutes, etc.
    int averageTime = totalTime / currChain[3];
    hours = averageTime / 360;
    minutes = (averageTime - (hours * 360)) / 60;
    seconds = (averageTime - (hours * 360) - (minutes * 60)) % 60;

    std::cout << "average_job_time: " << std::setfill('0') << std::setw(2)
              << hours << ":" << std::setfill('0') << std::setw(2) << minutes
              << ":" << std::setfill('0') << std::setw(2) << seconds << "\n-"
              << std::endl;
  }
}