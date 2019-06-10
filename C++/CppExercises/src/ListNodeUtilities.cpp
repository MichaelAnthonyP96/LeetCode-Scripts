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

ListNode* ListNodeUtilities::deleteDuplicates(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;//base case
    ListNode* current = head;//current pointer to iterate through the list
    while(current != NULL && current->next != NULL){
        //if the two values are the same, skip over the next Node and try again
        if(current->val == current->next->val){
            current->next = current->next->next;
            continue;
        }
        else{
            //only when the current->val and current->next->val are different do you continue down
            //the list
            current = current->next;
        }
    }
    //return the head to the removed duplicates list
    return head;
}

ListNode* ListNodeUtilities::addTwoNumbers(ListNode* l1, ListNode* l2) {
    /*You are given two non-empty linked lists representing two non-negative integers. The digits are
     *stored in reverse order and each of their nodes contain a single digit. Add the two numbers and
     *return it as a linked list.You may assume the two numbers do not contain any leading zero,
     *except the number 0 itself.
     */
    ListNode* returnHeader = l1;
    short carryOver = 0;
    while(l1 != NULL && l2 != NULL){
        if(l1->val + l2->val + carryOver < 10){
            l1->val = l1->val + l2->val + carryOver;
            carryOver = 0;
        }
        else{
            short temp = (l1->val + l2->val + carryOver );
            l1->val =  temp % 10;
            carryOver = temp / 10;
            if(l1->next == NULL){
                ListNode* tail = new ListNode(carryOver);
                l1->next = tail;
                break;
            }
        }
        if(l1->next == NULL){
            l1->next = l2->next;
            break;
        }
        if(l2->next == NULL){
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

int ListNodeUtilities::linkedListToInteger(ListNode* l){
    //return value
    int ret = 0;
    //exponent value used to march through linked list
    int exponent = 0;
    //until the end of the list
    while(l != NULL){
        //Power function is accurately enlarge the current value by the proper power of ten
        ret += (l->val * pow(10,exponent));
        //increment the exponent and move onto the next Node
        exponent++;
        l = l->next;
    }
    return ret;
}

ListNode* ListNodeUtilities::integerToLinkedList(int num){
    //save the head of the list to return
    ListNode* head = new ListNode(num % 10);
    //pointer used to march through the list
    ListNode* ptr = head;
    //remove the last digit since we used it for the header
    num /= 10;
    //while the number is not zero
    while(num > 0){
        //create a new node initialized to the last digit in the number to attach to the end of the list
        ptr->next = new ListNode(num % 10);
        //march the pointer along
        ptr = ptr->next;
        //remove the last digit
        num /= 10;
    }
    return head;
}
