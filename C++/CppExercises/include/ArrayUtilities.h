//
//  ArrayUtilities.hpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#ifndef ArrayUtilities_h
#define ArrayUtilities_h

#include <stdio.h>
#include <vector>

class ArrayUtilities{
public:
    static void mergeSortedArrays(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
    static std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A);
    static std::vector<int> sortArrayByParity(std::vector<int>& A);
    static std::vector<int> sortedSquares(std::vector<int>& A);
    static std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& A);
    static int maxSubArray(std::vector<int>& nums);
    static int maxProfit(std::vector<int>& prices);
    static std::vector<int> sortArray(std::vector<int>& nums);
    static std::vector<int> mergeTwoSortedArrays(std::vector<int> l1, std::vector<int> l2);
    static std::vector<int> mergeSortAscending(std::vector<int>& nums);
};

#endif /* ArrayUtilities_hpp */
