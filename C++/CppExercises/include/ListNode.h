//
//  ListNode.h
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#ifndef ListNode_h
#define ListNode_h

class ListNode {
public:
    ListNode(int x); //constructor
    virtual ~ListNode(); //destructor
    ListNode* next; //ListNode pointer next
    int val; //Value
};

#endif /* ListNode_h */
