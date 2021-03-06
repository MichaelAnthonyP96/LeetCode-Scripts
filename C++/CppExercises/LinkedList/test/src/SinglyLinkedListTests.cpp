//
//  listUtilTests.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 8/14/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "gtest/gtest.h"
#include "SinglyLinkedList.hpp"

TEST(sort, ReverseOrder)
{
    SinglyLinkedList<int> list;
    list.insertBack(4);
    list.insertBack(3);
    list.insertBack(2);
    list.insertBack(1);
    ASSERT_EQ(list.size(), 4);
    list.sort();
    SinglyLinkedList<int>::ListIterator itr(list.begin());

    EXPECT_EQ(*itr, 1);
    EXPECT_EQ(*(++itr), 2);
    EXPECT_EQ(*(++itr), 3);
    EXPECT_EQ(*(++itr), 4);
    EXPECT_TRUE((++itr) == list.end());
}

TEST(sort, RandomOrder)
{
    SinglyLinkedList<int> list;
    list.insertBack(1021);
    list.insertBack(32);
    list.insertBack(66);
    list.insertBack(12);
    list.insertBack(57);
    ASSERT_EQ(list.size(), 5);
    list.sort();
    SinglyLinkedList<int>::ListIterator itr(list.begin());

    EXPECT_EQ(*itr, 12);
    EXPECT_EQ(*(++itr), 32);
    EXPECT_EQ(*(++itr), 57);
    EXPECT_EQ(*(++itr), 66);
    EXPECT_EQ(*(++itr), 1021);
    EXPECT_TRUE((++itr) == list.end());
}

TEST(sort, DuplicatesIncluded)
{
    SinglyLinkedList<int> list;
    list.insertBack(1021);
    list.insertBack(32);
    list.insertBack(66);
    list.insertBack(66);
    list.insertBack(66);
    ASSERT_EQ(list.size(), 5);
    list.sort();
    SinglyLinkedList<int>::ListIterator itr(list.begin());

    EXPECT_EQ(*itr, 32);
    EXPECT_EQ(*(++itr), 66);
    EXPECT_EQ(*(++itr), 66);
    EXPECT_EQ(*(++itr), 66);
    EXPECT_EQ(*(++itr), 1021);
    EXPECT_TRUE((++itr) == list.end());
}

TEST(API, RemoveDuplicates)
{
    SinglyLinkedList<int> list;
    list.insertBack(1021);
    list.insertBack(32);
    list.insertBack(66);
    list.insertBack(66);
    list.insertBack(66);
    ASSERT_EQ(list.size(), 5);
    list.sort();
    list.removeDuplicates();
    ASSERT_EQ(list.size(), 3);
    SinglyLinkedList<int>::ListIterator itr(list.begin());

    EXPECT_EQ(*itr, 32);
    EXPECT_EQ(*(++itr), 66);
    EXPECT_EQ(*(++itr), 1021);
    EXPECT_TRUE((++itr) == list.end());
}

TEST(sort, NullList)
{
    SinglyLinkedList<int> list;
    EXPECT_NO_THROW(list.sort());
    SinglyLinkedList<int>::ListIterator itr(list.begin());
    EXPECT_TRUE(itr == list.end());
}

TEST(addTwoNumbers, TwoPositiveEqualLengthLists)
{
    // represents the number 243
    SinglyLinkedList<int> list1;
    list1.insertFront(2);
    list1.insertFront(4);
    list1.insertFront(3);

    // represents the number 564
    SinglyLinkedList<int> list2;
    list2.insertFront(5);
    list2.insertFront(6);
    list2.insertFront(4);

    // result should be 807
    auto* result = SinglyLinkedList<int>::addTwoNumbers(list1, list2);
    // When adding the individual digits, this result should equal 15
    ASSERT_EQ(15, SinglyLinkedList<int>::sum(result->begin()));
    SinglyLinkedList<int>::ListIterator itr(result->begin());
    EXPECT_EQ(*itr, 7);
    EXPECT_EQ(*(++itr), 0);
    EXPECT_EQ(*(++itr), 8);
    EXPECT_TRUE((++itr) == result->end());
}

// TODO(mapope): Add negative flag to addTwoNumbers() and Sum() methods
TEST(addTwoNumbers, DISABLED_TwoNegativeEqualLengthLists)
{
    // represents the number -243
    SinglyLinkedList<int> list1;
    list1.insertFront(-2);
    list1.insertFront(4);
    list1.insertFront(3);

    // represents the number -564
    SinglyLinkedList<int> list2;
    list2.insertFront(-5);
    list2.insertFront(6);
    list2.insertFront(4);

    // result should be -807
    auto* result = SinglyLinkedList<int>::addTwoNumbers(list1, list2);
    // When adding the individual digits, this result should equal 15
    ASSERT_EQ(-15, SinglyLinkedList<int>::sum(result->begin()));
    SinglyLinkedList<int>::ListIterator itr(result->begin());
    EXPECT_EQ(*itr, 7);
    EXPECT_EQ(*(++itr), 0);
    EXPECT_EQ(*(++itr), 8);
    EXPECT_TRUE((++itr) == result->end());
}

TEST(getIntersectionNode, TwoUnEqualLengthLists)
{
    // 4 -> 1
    SinglyLinkedList<int>* listA = SinglyLinkedList<int>::integerToLinkedList(41);

    // 5 -> 6 -> 1
    SinglyLinkedList<int>* listB = SinglyLinkedList<int>::integerToLinkedList(561);

    // 8 -> 4 -> 5
    SinglyLinkedList<int>* listC = SinglyLinkedList<int>::integerToLinkedList(845);

    // Attach 8 -> 4 -> 5 to the end of both lists
    listA->append(*listC);
    listB->append(*listC);

    // The result should be the start of listC, which was appended onto A & B
    auto result = SinglyLinkedList<int>::getIntersectionNode(*listA, *listB);
    ASSERT_EQ(listC->begin().getNode(), result);
}

TEST(getIntersectionNode, NoIntersection)
{
    // 2 -> 6 -> 4
    SinglyLinkedList<int>* listA = SinglyLinkedList<int>::integerToLinkedList(264);

    // 1 -> 5
    SinglyLinkedList<int>* listB = SinglyLinkedList<int>::integerToLinkedList(15);

    // The result should be nullptr since the lists do not share any common nodes
    auto result = SinglyLinkedList<int>::getIntersectionNode(*listA, *listB);
    ASSERT_EQ(nullptr, result);
}

TEST(findCycle, noCycle)
{
    // 2 -> 6 -> 4
    SinglyLinkedList<int>* listA = SinglyLinkedList<int>::integerToLinkedList(264);

    ASSERT_FALSE(SinglyLinkedList<int>::hasCycle(*listA));
}

TEST(findCycle, cycleFound)
{
    // 2 -> 6 -> 4
    SinglyLinkedList<int>* listA = SinglyLinkedList<int>::integerToLinkedList(264);

    auto itr = listA->begin();
    itr++;
    itr++;
    itr.getNode()->next = listA->begin().getNode();

    ASSERT_TRUE(SinglyLinkedList<int>::hasCycle(*listA));
}

TEST(isPalindrome, oddLength)
{
    SinglyLinkedList<int>* listA = SinglyLinkedList<int>::integerToLinkedList(101);
    SinglyLinkedList<int>* listB = SinglyLinkedList<int>::integerToLinkedList(1);
    SinglyLinkedList<int>* listC = SinglyLinkedList<int>::integerToLinkedList(12321);

    ASSERT_TRUE(SinglyLinkedList<int>::isPalindrome(*listA));
    ASSERT_TRUE(SinglyLinkedList<int>::isPalindrome(*listB));
    ASSERT_TRUE(SinglyLinkedList<int>::isPalindrome(*listC));
}

TEST(isPalindrome, evenLength)
{
    SinglyLinkedList<int>* listA = SinglyLinkedList<int>::integerToLinkedList(1001);
    SinglyLinkedList<int>* listB = SinglyLinkedList<int>::integerToLinkedList(10);
    SinglyLinkedList<int>* listC = SinglyLinkedList<int>::integerToLinkedList(121111);

    ASSERT_TRUE(SinglyLinkedList<int>::isPalindrome(*listA));
    ASSERT_FALSE(SinglyLinkedList<int>::isPalindrome(*listB));
    ASSERT_FALSE(SinglyLinkedList<int>::isPalindrome(*listC));
}

TEST(removeElements, multipleDeletes)
{
    // 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    SinglyLinkedList<int>* listA = SinglyLinkedList<int>::integerToLinkedList(1263456);
    SinglyLinkedList<int>::removeElements(*listA, 6);
    auto itr = listA->begin();

    ASSERT_EQ(*itr, 1);
    ++itr;
    ASSERT_EQ(*itr, 2);
    ++itr;
    ASSERT_EQ(*itr, 3);
    ++itr;
    ASSERT_EQ(*itr, 4);
    ++itr;
    ASSERT_EQ(*itr, 5);
}

TEST(removeElements, headDelete)
{
    // 6 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    SinglyLinkedList<int>* listA = SinglyLinkedList<int>::integerToLinkedList(6263456);
    SinglyLinkedList<int>::removeElements(*listA, 6);
    auto itr = listA->begin();

    ASSERT_EQ(*itr, 2);
    ++itr;
    ASSERT_EQ(*itr, 3);
    ++itr;
    ASSERT_EQ(*itr, 4);
    ++itr;
    ASSERT_EQ(*itr, 5);
}

TEST(removeElements, nullList)
{
    // null
    SinglyLinkedList<int> listA = SinglyLinkedList<int>();
    ASSERT_NO_THROW(SinglyLinkedList<int>::removeElements(listA, 12));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}