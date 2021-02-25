//
//  ListNodeUtilities.hpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#ifndef ListNodeUtilities_hpp
#define ListNodeUtilities_hpp

#include <cstdio>

#include "ListNode.hpp"

template <typename T>
class ListNodeUtilities {
   public:
    ListNode<T>* deleteDuplicates(ListNode<T>* head);
    ListNode<T>* addTwoNumbers(ListNode<T>* l1, ListNode<T>* l2);
    T linkedListToInteger(ListNode<T>* l);
    ListNode<T>* integerToLinkedList(T num);
    ListNode<T>* middleNode(ListNode<T>* head);
    ListNode<T>* reverseList(ListNode<T>* head);
    void deleteNode(ListNode<T>* node);
    ListNode<T>* insertionSort(ListNode<T>* head);
};

#include "ListNodeUtilities.hpp"
#endif /* ListNodeUtilities_hpp */
