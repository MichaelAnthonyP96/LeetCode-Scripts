//
//  listUtilTests.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 8/14/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "ListNode.hpp"
#include "ListNodeUtilities.hpp"
#include "catch.hpp"

TEST_CASE("sortList", "") {
  ListNode l1(1);
  ListNode l2(2);
  ListNode l3(3);
  ListNode l4(4);

  l4.next = &l2;
  l2.next = &l1;
  l1.next = &l3;

  ListNode* result = ListNodeUtilities::insertionSort(&l4);
  REQUIRE(result->val == 1);
  result = result->next;
  REQUIRE(result->val == 2);
  result = result->next;
  REQUIRE(result->val == 3);
  result = result->next;
  REQUIRE(result->val == 4);
  result = result->next;
  REQUIRE(result == nullptr);

}