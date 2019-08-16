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
