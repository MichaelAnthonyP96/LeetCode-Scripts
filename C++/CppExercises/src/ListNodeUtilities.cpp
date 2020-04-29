//
//  ListNodeUtilities.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "ListNodeUtilities.hpp"
#include "ListNode.hpp"
#include <cmath>

ListNode *ListNodeUtilities::deleteDuplicates(ListNode *head) {
  if (head == nullptr || head->next == nullptr)
    return head;            // base case
  ListNode *current = head; // current pointer to iterate through the list
  while (current != nullptr && current->next != nullptr) {
    // if the two values are the same, skip over the next Node and try again
    if (current->val == current->next->val) {
      current->next = current->next->next;
      continue;
    } else {
      // only when the current->val and current->next->val are different do you
      // continue down the list
      current = current->next;
    }
  }
  // return the head to the removed duplicates list
  return head;
}

/**You are given two non-empty linked lists representing two non-negative
 *integers. The digits are stored in reverse order and each of their nodes
 *contain a single digit. Add the two numbers and return it as a linked
 *list.You may assume the two numbers do not contain any leading zero, except
 *the number 0 itself.
 */
ListNode *ListNodeUtilities::addTwoNumbers(ListNode *l1, ListNode *l2) {

  ListNode *returnHeader = l1;
  short carryOver = 0;
  while (l1 != nullptr && l2 != nullptr) {
    if (l1->val + l2->val + carryOver < 10) {
      l1->val = l1->val + l2->val + carryOver;
      carryOver = 0;
    } else {
      short temp = (l1->val + l2->val + carryOver);
      l1->val = temp % 10;
      carryOver = temp / 10;
      if (l1->next == nullptr) {
        ListNode *tail = new ListNode(carryOver);
        l1->next = tail;
        break;
      }
    }
    if (l1->next == nullptr) {
      l1->next = l2->next;
      break;
    }
    if (l2->next == nullptr) {
      /*while(carryOver > 0){
       short temp = (l1->next->val + l2->next->val + carryOver );
       l1->next->val =  temp % 10;
       carryOver = temp / 10;
       l1 = l1->next;
       }*/
      l1->next->val += carryOver;
      break;
    }
    l1 = l1->next;
    l2 = l2->next;
  }
  return returnHeader;
}

int ListNodeUtilities::linkedListToInteger(ListNode *l) {
  // return value
  int ret = 0;
  // exponent value used to march through linked list
  int exponent = 0;
  // until the end of the list
  while (l != nullptr) {
    // Power function is accurately enlarge the current value by the proper
    // power of ten
    ret += (l->val * pow(10, exponent));
    // increment the exponent and move onto the next Node
    exponent++;
    l = l->next;
  }
  return ret;
}
/**
 * \brief Convert an integer to a linked list of nodes representing the digits
 *        of the original number
 * @param num Integer to convert to a linked list
 * @return ListNode* to the head of the resulting List
 */
ListNode *ListNodeUtilities::integerToLinkedList(int num) {
  // save the head of the list to return
  ListNode *head = new ListNode(num % 10);
  // pointer used to march through the list
  ListNode *ptr = head;
  // remove the last digit since we used it for the header
  num /= 10;
  // while the number is not zero
  while (num > 0) {
    // create a new node initialized to the last digit in the number to attach
    // to the end of the list
    ptr->next = new ListNode(num % 10);
    // march the pointer along
    ptr = ptr->next;
    // remove the last digit
    num /= 10;
  }
  return head;
}

/**Given a non-empty, singly linked list with head node head, return a middle
 *node of the linked list. If there are two middle nodes, return the second
 *middle node. O(n) time, O(1) space
 */
ListNode *ListNodeUtilities::middleNode(ListNode *head) {
  int count = 0;
  ListNode *temp = head;
  for (; temp != nullptr; temp = temp->next) {
    count++;
  }
  count = (count / 2) + 1;
  temp = head;
  for (int i = 1; i < count; i++) {
    temp = temp->next;
  }
  return temp;
}

/**
 * \brief Reverse a singly linked list. O(n) time and O(1) space
 */
ListNode *ListNodeUtilities::reverseList(ListNode *head) {
  if (head == nullptr || head->next == nullptr)
    return head;
  ListNode *temp1 = head;
  ListNode *temp2 = head->next;
  ListNode *temp3 = nullptr;
  head->next = nullptr;
  for (; temp2 != nullptr; temp1 = temp2, temp2 = temp3) {
    temp3 = temp2->next;
    temp2->next = temp1;
  }
  return temp1;
}

/** Write a function to delete a node (except the tail) in a singly linked list,
 * given only access to that node. The linked list will have at least two
 * elements. All of the nodes' values will be unique. The given node will not be
 * the tail and it will always be a valid node of the linked list.
 */
void ListNodeUtilities::deleteNode(ListNode *node) {
  ListNode *temp = node->next;
  node->val = temp->val;
  node->next = temp->next;
  delete temp;
}

/**
 * \brief insertion sort implementation O(n^2) method
 *
 * \param head Beginning of the linked list to be sorted
 * \return Beginning of the sorted linked list
 */
ListNode *ListNodeUtilities::insertionSort(ListNode *head) {
  if (head == nullptr || head->next == nullptr)
    return head;
  ListNode *currHead = head;
  ListNode *itr, *currMin;
  while (currHead->next != nullptr) {
    itr = currHead->next;
    currMin = currHead;
    while (itr != nullptr) {
      if (itr->val < currMin->val) {
        currMin = itr;
      }
      itr = itr->next;
    }
    std::swap(currHead->val, currMin->val);
    currHead = currHead->next;
  }
  return head;
}
