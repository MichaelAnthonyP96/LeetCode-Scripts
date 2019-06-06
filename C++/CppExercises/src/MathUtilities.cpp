//
//  MathUtilities.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "MathUtilities.h"

int MathUtilities::mySqrt(int x) {
    /*Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
     *Since the return type is an integer, the decimal digits are truncated and only the integer part
     *of the result is returned.
     */
    if( x <= 0) return 0; //base case of negatives and zero
    if( x == 1 ) return 1; //base case of 1
    unsigned int retVal = 1; //sqrt must be atleast 1
    while(true){
        //Since we are approaching from 1, if the current int and the next incremental int are
        //respectively less than or equal to and greater than the input x, we have found the truncated
        //sqrt integer value of x
        if( (retVal * retVal <= x) && ( (retVal+1) * (retVal+1) > x) ){
            return retVal;
        }
        else{
            retVal++;
        }
    }
}

int MathUtilities::climbStairs(int n) {
    /*You are climbing a stair case. It takes n steps to reach to the top. Each time you can either
     *climb 1 or 2 steps. In how many distinct ways can you climb to the top? Note: Given n will be a
     *positive integer.
     */
    if(n == 1) return 1; //base case of 1
    if(n == 2) return 2; //base case of 2
    unsigned int* array = new unsigned int[n]; //declare unsigned int array of size n
    array[0] = 1; //base case of 1
    array[1] = 2; //base case of 2
    //Iteratively populate the int array using the previous two terms. Since you can reach the stair
    //in question by taking x number of ways to get to stair i-1 and y number of ways to get to i-2,
    //to get to stair i all x and y number of ways are valid because you can take those paths and then
    //another one or two stairs respectively
    for(int i = 2; i < n; i++){
        array[i] = array[i-1] + array[i-2];
    }
    return array[n-1];
}
