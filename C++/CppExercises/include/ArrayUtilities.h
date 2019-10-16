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
    std::vector<int> sortedSquares(std::vector<int>& A);

};

#endif /* ArrayUtilities_hpp */
