//
//  ListNode.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include <cstdlib>

template <typename T>
ListNode::ListNode(T x) : val(x), next(nullptr) {}

template <typename T>
ListNode::ListNode(T x, ListNode* next) : val(x), next(next) {}

template <typename T>
ListNode::~ListNode() {
    delete next;
    next = nullptr;
}


