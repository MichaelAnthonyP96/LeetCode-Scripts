//
//  ArrayUtilities.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "ArrayUtilities.h"
#include <vector>

void ArrayUtilities::mergeSortedArrays(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        /*
         *Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
         *Note: The number of elements initialized in nums1 and nums2 are m and n respectively. You may
         *assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional
         *elements from nums2.
         */
        m--;
        n--;
        while(m >= 0 && n>= 0){
            if(nums1[m] >= nums2[n]){
                nums1[m+n+1] = nums1[m];
                m--;
            }
            else{
                nums1[m+n+1] = nums2[n];
                n--;
            }
        }
        
        while(n>=0){
            nums1[n] = nums2[n];
            n--;
        }
}

/*
 *Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.
 *To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0]
 *horizontally results in [0, 1, 1]. To invert an image means that each 0 is replaced by 1, and each 1 is replaced
 *by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
 */
std::vector<std::vector<int>> ArrayUtilities::flipAndInvertImage(std::vector<std::vector<int>>& A) {
    std::vector<std::vector<int>> B(A.size());
    //Reverse and flip the image at the same time
    for(int i = 0; i < A.size(); ++i){
        //B.reserve(vector<int>(A[i].size()));
        for(int j = A[i].size() - 1; j >= 0; --j){
            if(A[i][j] == 1)
                B[i].push_back(0);
            else
                B[i].push_back(1);
        }
    }
    return B;
}


