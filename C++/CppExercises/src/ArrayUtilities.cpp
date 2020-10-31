//
//  ArrayUtilities.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "ArrayUtilities.h"
#include <vector>

void ArrayUtilities::mergeSortedArrays(std::vector<int> &nums1, int m,
                                       std::vector<int> &nums2, int n) {
  /*
   *Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
   *one sorted array. Note: The number of elements initialized in nums1 and
   *nums2 are m and n respectively. You may assume that nums1 has enough space
   *(size that is greater or equal to m + n) to hold additional elements from
   *nums2.
   */
  m--;
  n--;
  while (m >= 0 && n >= 0) {
    if (nums1[m] >= nums2[n]) {
      nums1[m + n + 1] = nums1[m];
      m--;
    } else {
      nums1[m + n + 1] = nums2[n];
      n--;
    }
  }

  while (n >= 0) {
    nums1[n] = nums2[n];
    n--;
  }
}

/*
 *Given a binary matrix A, we want to flip the image horizontally, then invert
 *it, and return the resulting image. To flip an image horizontally means that
 *each row of the image is reversed.  For example, flipping [1, 1, 0]
 *horizontally results in [0, 1, 1]. To invert an image means that each 0 is
 *replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1]
 *results in [1, 0, 0].
 */
std::vector<std::vector<int>>
ArrayUtilities::flipAndInvertImage(std::vector<std::vector<int>> &A) {
  std::vector<std::vector<int>> B(A.size());
  // Reverse and flip the image at the same time
  for (int i = 0; i < A.size(); ++i) {
    // B.reserve(vector<int>(A[i].size()));
    for (int j = A[i].size() - 1; j >= 0; --j) {
      if (A[i][j] == 1)
        B[i].push_back(0);
      else
        B[i].push_back(1);
    }
  }
  return B;
}

/*
 * Given an array A of non-negative integers, return an array consisting of all
 * the even elements of A, followed by all the odd elements of A. You may return
 * any answer array that satisfies this condition.
 */

std::vector<int> ArrayUtilities::sortArrayByParity(std::vector<int> &A) {
  std::vector<int> even, odd;
  for (int i = 0; i < A.size(); ++i) {
    // Even case, add to the even vector
    if ((A[i] % 2) == 0) {
      even.push_back(A[i]);
    } else { // Odd case, add to the odd vector
      odd.push_back(A[i]);
    }
  }
  even.insert(even.end(), odd.begin(), odd.end());
  return even;
}

/*Given an array of integers A sorted in non-decreasing order, return an array
 *of the squares of each number, also in sorted non-decreasing order.
 */
std::vector<int> ArrayUtilities::sortedSquares(std::vector<int> &A) {
  std::vector<int> ret(A.size());
  int a, b;
  for (int i = 0, j = A.size() - 1, it = A.size() - 1; i <= j;) {
    a = A[i] * A[i];
    b = A[j] * A[j];
    if (a >= b) {
      ret[it] = a;
      --it;
      i++;
    } else {
      ret[it] = b;
      --it;
      --j;
    }
  }
  return ret;
}

std::vector<std::vector<int>>
ArrayUtilities::transpose(std::vector<std::vector<int>> &A) {
  std::vector<std::vector<int>> ret(A[0].size());
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < A[0].size(); ++j) {
      ret[j].push_back(A[i][j]);
    }
  }
  return ret;
}

// O(n) runtime maxSub Array Algorithm
// O(1) space required
// Considered an "online" algorithm b/c it requres constant space,
// runs in linear time and can return the solution at any time with
// only the data that it currently has

int ArrayUtilities::maxSubArray(std::vector<int> &nums) {

  int thisSum = 0, maxSum = INT_MIN;
  for (int i = 0; i < nums.size(); ++i) {
    thisSum += nums[i];
    if (thisSum > maxSum)
      maxSum = thisSum;
    if (thisSum < 0)
      thisSum = 0;
  }
  return maxSum;
}

/**
 * \brief Design an algorithm to find the maximum profit.
 *
 * Say you have an array for which the ith element is the price of a given stock
 * on day i. You may complete as manytransactions as you like (i.e., buy one and
 * sell one share of the stock multiple times).
 *
 * Note: You may not engage in multiple transactions at the same time (i.e., you
 * must sell the stock before you buy again).
 * @param prices list of prices at given time intervals
 * @return the maximum profit over that entire time interval
 */

int ArrayUtilities::maxProfit(std::vector<int> &prices) {
  int profit = 0, size = prices.size();
  std::vector<int> profits(size, 0);
  std::vector<int> previous(size, 0);
  for (int i = 0; i < (size - 1); ++i) {
    if (prices[i] < prices[i + 1]) {
      // opportunity for profit
      profits[i] = prices[i + 1] - prices[i];
      previous[i + 1] = i;
      // more money could've been made if the stock was bought earlier
      if (profits[previous[i]] > profits[i]) {
        int itr = i;
        while (previous[itr] != 0) {
          // reset the profit value, since that transaction now will not happen
          profits[itr] = 0;
          itr = previous[itr];
        }
        profits[itr] = prices[i + 1] - prices[itr];
      }
    }
  }

  // loop over the profits vector and sum up the transactions
  for (int j = 0; j < size; ++j) {
    profit += profits[j];
  }
  return profit;
}

std::vector<int> ArrayUtilities::sortArray(std::vector<int> &nums) {
  return mergeSortAscending(nums);
}

std::vector<int> ArrayUtilities::mergeTwoSortedArrays(std::vector<int> l1,
                                                      std::vector<int> l2) {
  int idx = 0;
  std::vector<int> ret(l1.size() + l2.size());
  auto it1 = l1.begin(), it2 = l2.begin();
  while (it1 != l1.end() || it2 != l2.end()) {
    if (it1 == l1.end()) {
      ret[idx++] = *it2++;
    } else if (it2 == l2.end()) {
      ret[idx++] = *it1++;
    } else if (*it1 <= *it2) {
      ret[idx++] = *it1++;
    } else {
      ret[idx++] = *it2++;
    }
  }
  return ret;
}

std::vector<int> ArrayUtilities::mergeSortAscending(std::vector<int> &nums) {
  // base case - comparing two neighboring indices
  if (nums.size() == 1) {
    return nums;
  } else if (nums.size() == 2) {
    // swap the two if low is
    if (nums[0] > nums[1]) {
      std::swap(nums[0], nums[1]);
    }
    return nums;
  } else {
    // recursively sort the left and right halves of the array
    int middle = nums.size() / 2;
    // merge the two sorted halves together
    std::vector<int> v1(nums.begin(), nums.begin() + middle);
    std::vector<int> v2(nums.begin() + middle, nums.begin() + nums.size());
    v1 = mergeSortAscending(v1);
    v2 = mergeSortAscending(v2);
    return mergeTwoSortedArrays(v1, v2);
  }
}

bool ArrayUtilities::canMakeArithmeticProgression(std::vector<int> &arr) {
  if (arr.empty() || arr.size() == 1) {
    return true;
  } else {
    std::sort(arr.begin(), arr.end());
    int stride = arr[1] - arr[0];
    for (int i = 1; i < (arr.size() - 1); ++i) {
      if (stride != (arr[i + 1] - arr[i])) {
        return false;
      }
    }
    return true;
  }
}