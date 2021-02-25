//
//  ListNode.h
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#ifndef ListNode_hpp
#define ListNode_hpp

template <typename T>
class ListNode {
   public:
    explicit ListNode(T x);         // constructor
    ListNode(T x, ListNode *next);  // constructor
    virtual ~ListNode();            // destructor
   private:
    ListNode *next;  // ListNode pointer next
    T val;           // Value
};

#include "ListNode.cpp"
#endif // ListNode_hpp
