//
//  ListNodeUtilities.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "ListNodeUtilities.hpp"

#include <cmath>

#include "ListNode.hpp"

template <typename T>
ListNode<T> *ListNodeUtilities<T>::deleteDuplicates(ListNode<T> *head) {
    if (head == nullptr || head->next == nullptr) return head;  // base case
    ListNode<T> *current = head;  // current pointer to iterate through the list
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
template <typename T>
ListNode<T> *ListNodeUtilities<T>::addTwoNumbers(ListNode<T> *l1, ListNode<T> *l2) {
    ListNode<T> *returnHeader = l1;
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
                auto *tail = new ListNode<T>(carryOver);
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

template <typename T>
T ListNodeUtilities<T>::linkedListToInteger(ListNode<T> *l) {
    // return value
    T ret = 0;
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
template <typename T>
ListNode<T> *ListNodeUtilities<T>::integerToLinkedList(T num) {
    // save the head of the list to return
    auto *head = new ListNode<T>(num % 10);
    // pointer used to march through the list
    ListNode<T> *ptr = head;
    // remove the last digit since we used it for the header
    num /= 10;
    // while the number is not zero
    while (num > 0) {
        // create a new node initialized to the last digit in the number to attach
        // to the end of the list
        ptr->next = new ListNode<T>(num % 10);
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
template <typename T>
ListNode<T> *ListNodeUtilities<T>::middleNode(ListNode<T> *head) {
    int count = 0;
    ListNode<T> *temp = head;
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
template <typename T>
ListNode<T> *ListNodeUtilities<T>::reverseList(ListNode<T> *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode<T> *temp1 = head;
    ListNode<T> *temp2 = head->next;
    ListNode<T> *temp3 = nullptr;
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
template <typename T>
void ListNodeUtilities<T>::deleteNode(ListNode<T> *node) {
    ListNode<T> *temp = node->next;
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
template <typename T>
ListNode<T> *ListNodeUtilities<T>::insertionSort(ListNode<T> *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode<T> *currHead = head;
    ListNode<T> *itr, *currMin;
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
