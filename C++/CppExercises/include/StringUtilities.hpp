//
//  StringUtilities.hpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 8/14/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#ifndef StringUtilities_hpp
#define StringUtilities_hpp

#include <stdio.h>
//#include <iostream>
#include <string>

using namespace std;

class StringUtilities{
public:
    static string defangIPaddr(string address);
    static int numJewelsInStones(string J, string S);
    static string toLowerCase(string str);
};


#endif /* StringUtilities_hpp */
