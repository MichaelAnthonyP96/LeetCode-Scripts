//
//  ListNodeUtilities.hpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#ifndef ListNodeUtilities_hpp
#define ListNodeUtilities_hpp

#include <stdio.h>
#include "ListNode.hpp"

class ListNodeUtilities{
public:
    static ListNode* deleteDuplicates(ListNode* head);
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    static int linkedListToInteger(ListNode* l);
    static ListNode* integerToLinkedList(int num);
    static ListNode* middleNode(ListNode* head);
    static ListNode* reverseList(ListNode* head);
};
    
#endif /* ListNodeUtilities_hpp */
