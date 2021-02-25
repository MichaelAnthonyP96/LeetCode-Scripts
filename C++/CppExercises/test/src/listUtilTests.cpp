//
//  listUtilTests.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 8/14/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "ListNode.hpp"
#include "ListNodeUtilities.hpp"
#include "gtest/gtest.h"

TEST(sortList, AscendingOrder) {
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);

    l4.next = &l2;
    l2.next = &l1;
    l1.next = &l3;

    ListNode *result = ListNodeUtilities::insertionSort(&l4);
    EXPECT_EQ(result->val, 1);
    result = result->next;
    EXPECT_EQ(result->val, 2);
    result = result->next;
    EXPECT_EQ(result->val, 3);
    result = result->next;
    EXPECT_EQ(result->val, 4);
    result = result->next;
    EXPECT_EQ(result, nullptr);
}

TEST(Merge, TwoNonNegativeLists) {
    ListNode<int> l3(3);
    ListNode<int> l2(4, &l3);
    ListNode<int> l1(2, &l2);

    ListNode<int> l6(4);
    ListNode<int> l5(6, &l6);
    ListNode<int> l4(5, &l5);

    //  ListNode *result = ListNodeUtilities::insertionSort(&l4);
    auto result = ListNodeUtilities::addTwoNumbers(&l1, &l4);
    //  EXPECT_EQ(result->val, 1);
    //  result = result->next;
    //  EXPECT_EQ(result->val, 2);
    //  result = result->next;
    //  EXPECT_EQ(result->val, 3);
    //  result = result->next;
    //  EXPECT_EQ(result->val, 4);
    //  result = result->next;
    //  EXPECT_EQ(result, nullptr);
}