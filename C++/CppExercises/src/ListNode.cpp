//
//  ListNode.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include <stdlib.h>
#include "ListNode.hpp"

ListNode::ListNode(const int x) : val(x), next(NULL) {}

ListNode::~ListNode() {
    next = NULL;
    delete next;
}


