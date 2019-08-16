//
//  StringUtilities.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 8/14/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "StringUtilities.hpp"
//Given a valid (IPv4) IP address, return a defanged version of that IP address.
//A defanged IP address replaces every period "." with "[.]".
string StringUtilities::defangIPaddr(string address){
    size_t f = 0;
    int place = 0;
    do{
        f = address.substr(place,address.length()-place).find(".");
        if(f != std::string::npos){
            address.insert(f+place,"[");
            address.insert(f+place+2,"]");
            place = place + f + 2;
        }
        
    }while(f != std::string::npos);
    return address;
}

//You're given strings J representing the types of stones that are jewels, and S representing the stones you have.
//Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
//The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so
//"a" is considered a different type of stone from "A".
int StringUtilities::numJewelsInStones(string J, string S) {
    std::string::iterator it = S.begin();
    int ret = 0;
    while(it != S.end()){
        if( J.find(*it) != std::string::npos){
            ++ret;
        }
        ++it;
    }
    return ret;
}

//Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
string StringUtilities::toLowerCase(string str) {
    std::string s;
    for(int i = 0; i < str.length(); ++i){
        s.insert(s.end(), std::tolower(str[i]));
    }
    return s;
}
