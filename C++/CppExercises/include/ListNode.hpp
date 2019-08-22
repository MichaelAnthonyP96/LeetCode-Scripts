//
//  ListNode.h
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#ifndef ListNode_hpp
#define ListNode_hpp

class ListNode {
public:
    ListNode(int x); //constructor
    ListNode(int x, ListNode* next); // constructor
    virtual ~ListNode(); //destructor
    ListNode* next; //ListNode pointer next
    int val; //Value
};

#endif /* ListNode_h */
