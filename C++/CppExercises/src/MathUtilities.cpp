//
//  MathUtilities.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "MathUtilities.h"
#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

/**
 * \brief Compute and return the square root of an integer
 *
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer. Since the return type is an integer, the decimal digits
 * are truncated and only the integer part of the result is returned.
 *
 * \param x number to compute the square root of
 * \return the square root, truncated to an integer
 */

int MathUtilities::mySqrt(int x) {
  if (x <= 0)
    return 0; // base case of negatives and zero
  if (x == 1)
    return 1;              // base case of 1
  unsigned int retVal = 1; // sqrt must be atleast 1
  while (true) {
    // Since we are approaching from 1, if the current int and the next
    // incremental int are respectively less than or equal to and greater than
    // the input x, we have found the truncated sqrt integer value of x
    if ((retVal * retVal <= x) && ((retVal + 1) * (retVal + 1) > x)) {
      return retVal;
    } else {
      retVal++;
    }
  }
}

/**
 * \brief how many distinct ways can you climb to the top of a set of stairs.
 *
 * You are climbing a stair case. It takes n steps to reach to the top. Each
 * time you can either climb 1 or 2 steps. In how many distinct ways can you
 * climb to the top? Note: Given n will be a positive integer.
 *
 * @param n number of stairs to climb
 * @return number of ways to climb the stairs
 */
int MathUtilities::climbStairs(int n) {
  if (n == 1)
    return 1; // base case of 1
  if (n == 2)
    return 2; // base case of 2
  unsigned int *array =
      new unsigned int[n]; // declare unsigned int array of size n
  array[0] = 1;            // base case of 1
  array[1] = 2;            // base case of 2
  // Iteratively populate the int array using the previous two terms. Since you
  // can reach the stair in question by taking x number of ways to get to stair
  // i-1 and y number of ways to get to i-2, to get to stair i all x and y number
  // of ways are valid because you can take those paths and then another one or
  // two stairs respectively
  for (int i = 2; i < n; i++) {
    array[i] = array[i - 1] + array[i - 2];
  }
  return array[n - 1];
}

std::string MathUtilities::addBinary(std::string a, std::string b) {
  std::vector<char> v;
  int A = std::stoi(a);
  int B = std::stoi(b);
  int Apop = 0;
  int Bpop = 0;
  bool carry = false;
  do {
    Apop = A % 10;
    A = A / 10;
    Bpop = B % 10;
    B = B / 10;
    if ((Apop == 0) && (Bpop == 0)) {
      if (carry == false) {
        //                std::stringstream temp;
        //                temp << ss.rdbuf();
        //                temp << '0';
        //                ss = std::move(temp);
        v.push_back('0');
        continue;
      } else {
        //                std::stringstream temp;
        //                temp << ss.rdbuf();
        //                temp << '1';
        //                ss = std::move(temp);
        v.push_back('1');
        carry = false;
        continue;
      }
    }
    if (((Apop == 0) && (Bpop == 1)) || ((Apop == 1) && (Bpop == 0))) {
      if (carry == false) {
        //                std::stringstream temp;
        //                temp << ss.rdbuf();
        //                temp << '1';
        //                ss = std::move(temp);
        v.push_back('1');
        continue;
      } else {
        //                std::stringstream temp;
        //                temp << ss.rdbuf();
        //                temp << '0';
        //                ss = std::move(temp);
        v.push_back('0');
        carry = true;
        continue;
      }
    }
    if ((Apop == 1) && (Bpop == 1)) {
      if (carry == false) {
        //                std::stringstream temp;
        //                temp << ss.rdbuf();
        //                temp << '0';
        //                ss = std::move(temp);
        v.push_back('0');
        carry = true;
        continue;
      } else {
        //                std::stringstream temp;
        //                temp << ss.rdbuf();
        //                temp << '1';
        //                ss = std::move(temp);
        v.push_back('1');
        carry = true;
        continue;
      }
    }
  } while ((A != 0) || (B != 0));
  if (carry == true)
    v.push_back('1');
  std::stringstream ss;
  for (auto it = v.rbegin(); it != v.rend(); it++) {
    ss << *it;
  }
  return ss.str();
}

/** \brief rotate an array to the right by k steps
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 */
void MathUtilities::rotate(std::vector<int> &nums, int k) {
  std::vector<int> v;
  short s = nums.size();
  if (k > s)
    k = k % s;
  int kk = k;
  // copy the last k elements
  for (; kk > 0; --kk) {
    v.push_back(nums[s - kk]);
  }
  // shift s - k elements k to the right
  for (int i = s - k - 1; i >= 0; --i) {
    nums[i + k] = nums[i];
  }
  // insert the first k elements
  for (int h = 0; h < k; ++h) {
    nums[h] = v[h];
  }
}

/** \brief Find the number with a single instance in a list of numbers
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * \return the single number in the vector of numbers
 */
int singleNumber(vector<int> &nums) {
  if (nums.size() == 1)
    return nums[0];
  std::set<int> s;
  s.insert(nums[0]);
  set<int>::iterator it;
  set<int>::iterator e = s.end();
  for (int i = 1; i < nums.size(); ++i) {
    it = s.find(nums[i]);
    if (it == e)
      s.insert(nums[i]);
    else
      s.erase(it);
  }
  return *(s.begin());
}

/**
 * \brief: determine whether a number is a happy number.
 *
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 *
 * \param n: starting integer to determine if it is a happy number
 */
bool MathUtilities::isHappy(int n) {
  std::set<int> s;
  std::set<int>::iterator it = s.end();
  int result = n;
  while (result != 1) {
    result = sumDigitSquares(result);
    if (s.find(result) != s.end()) {
      return false;
    }
    s.insert(result);
  }
  return true;
}

/**
 * \brief isHappy() helper method to calculate the sum of individual digit
 *        squares
 *
 * \param n input number to sum the digit squares of
 * \return the summed result
 */
int MathUtilities::sumDigitSquares(int n) {
  int sum = 0;
  while (n != 0) {
    sum += std::pow((n % 10), 2);
    n /= 10;
  }
  return sum;
}

/**
 * \brief move all 0's to the end of it while maintaining the relative order of
 * the non-zero elements
 *
 * \param nums input vector of numbers to move as described
 */
void MathUtilities::moveZeroes(std::vector<int> &nums) {
  int totalSize = nums.size();
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] == 0) {
      int j = i + 1;
      while ((j < totalSize) && (nums[j] == 0)) {
        ++j;
      }
      if (j >= totalSize)
        return;
      std::swap(nums[i], nums[j]);
    }
  }
}