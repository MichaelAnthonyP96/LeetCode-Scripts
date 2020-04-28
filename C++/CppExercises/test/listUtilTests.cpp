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

  ListNodeUtilities::sortList(&l4);

}