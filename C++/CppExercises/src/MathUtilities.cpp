//
//  MathUtilities.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "MathUtilities.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>

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

std::string MathUtilities::addBinary(std::string a, std::string b) {
    std::vector<char> v;
    int A = std::stoi(a);
    int B = std::stoi(b);
    int Apop = 0;
    int Bpop = 0;
    bool carry = false;
    do{
        Apop = A % 10;
        A = A / 10;
        Bpop = B % 10;
        B = B / 10;
        if( (Apop == 0) && (Bpop == 0) ){
            if(carry == false){
//                std::stringstream temp;
//                temp << ss.rdbuf();
//                temp << '0';
//                ss = std::move(temp);
                v.push_back('0');
                continue;
            }
            else{
//                std::stringstream temp;
//                temp << ss.rdbuf();
//                temp << '1';
//                ss = std::move(temp);
                v.push_back('1');
                carry = false;
                continue;
            }
        }
        if( ((Apop == 0) && (Bpop == 1)) || ((Apop == 1) && (Bpop == 0)) ){
            if(carry == false){
//                std::stringstream temp;
//                temp << ss.rdbuf();
//                temp << '1';
//                ss = std::move(temp);
                v.push_back('1');
                continue;
            }
            else{
//                std::stringstream temp;
//                temp << ss.rdbuf();
//                temp << '0';
//                ss = std::move(temp);
                v.push_back('0');
                carry = true;
                continue;
            }
        }
        if((Apop == 1) && (Bpop == 1)){
            if(carry == false){
//                std::stringstream temp;
//                temp << ss.rdbuf();
//                temp << '0';
//                ss = std::move(temp);
                v.push_back('0');
                carry = true;
                continue;
            }
            else{
//                std::stringstream temp;
//                temp << ss.rdbuf();
//                temp << '1';
//                ss = std::move(temp);
                v.push_back('1');
                carry = true;
                continue;
            }
        }
    }while( (A != 0) || (B != 0) );
    if(carry == true) v.push_back('1');
    std::stringstream ss;
    for(auto it = v.rbegin(); it != v.rend(); it++){
        ss << *it;
    }
    return ss.str();
}

//Given an array, rotate the array to the right by k steps, where k is non-negative.
void MathUtilities::rotate(std::vector<int>& nums, int k) {
    std::vector<int> v;
    short s = nums.size();
    if(k > s) k = k % s;
    int kk = k;
    //copy the last k elements
    for(; kk > 0; --kk){
        v.push_back(nums[s - kk]);
    }
     //shift s - k elements k to the right
     for(int i = s - k - 1; i >= 0; --i ){
         nums[i + k] = nums[i];
     }
     //insert the first k elements
     for(int h = 0; h < k; ++h){
         nums[h] = v[h];
     }
}

//Given a non-empty array of integers, every element appears twice except for one. Find that single one.
int singleNumber(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    std::set<int> s;
    s.insert(nums[0]);
    set<int>::iterator it;
    set<int>::iterator e = s.end();
    for(int i = 1; i < nums.size(); ++i){
        it = s.find(nums[i]);
        if(it == e)
            s.insert(nums[i]);
        else
            s.erase(it);
    }
    return *(s.begin());
}

