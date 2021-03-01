//
//  ListNodeUtilities.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

// #include "SinglyLinkedList.hpp"

#include <SinglyLinkedList.hpp>
#include <cmath>
#include <stack>

template<typename T>
SinglyLinkedList<T>::ListNode::ListNode(const T& x) : val(x), next(nullptr)
{
}

template<typename T>
SinglyLinkedList<T>::ListNode::ListNode(T x, ListNode* next) : val(x), next(next)
{
}

template<typename T>
SinglyLinkedList<T>::ListNode::~ListNode() = default;

template<typename T>
SinglyLinkedList<T>::ListNode::ListNode() : val(), next(nullptr)
{
}

template<typename T>
SinglyLinkedList<T>::ListIterator::ListIterator() : p(nullptr)
{
}

template<typename T>
SinglyLinkedList<T>::ListIterator::ListIterator(ListNode* x) : p(x)
{
}

template<typename T>
typename SinglyLinkedList<T>::ListIterator& SinglyLinkedList<T>::ListIterator::operator++()
{
    p = p->next;
    return *this;
}
template<typename T>
const typename SinglyLinkedList<T>::ListIterator SinglyLinkedList<T>::ListIterator::operator++(int)
{
    ListNode* r = p;
    p = p->next;
    return ListIterator(r);
}
template<typename T>
bool SinglyLinkedList<T>::ListIterator::operator==(const SinglyLinkedList::ListIterator& rhs)
{
    if (p == nullptr && rhs.p == nullptr)
    {
        return true;
    }
    else if (p != nullptr && rhs.p == nullptr || p == nullptr && rhs.p != nullptr)
    {
        return false;
    }
    else
    {
        return p == rhs.p;
    }
}
template<typename T>
bool SinglyLinkedList<T>::ListIterator::operator!=(const SinglyLinkedList::ListIterator& rhs)
{
    return p != rhs.p;
}
template<typename T>
const T& SinglyLinkedList<T>::ListIterator::operator*()
{
    return p->val;
}
template<typename T>
const T* SinglyLinkedList<T>::ListIterator::operator->()
{
    return &(p->val);
}
template<typename T>
typename SinglyLinkedList<T>::ListNode*& SinglyLinkedList<T>::ListIterator::getNode()
{
    return p;
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() : m_pHead(nullptr), m_pTail(nullptr), m_length(0)
{
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    clear();
}

template<class T>
template<class Iter>
SinglyLinkedList<T>::SinglyLinkedList(const Iter& begin_iterator, const Iter& end_iterator) :
    m_pHead(nullptr), m_pTail(nullptr), m_length(0)
{
    for (Iter i = begin_iterator; i != end_iterator; ++i)
    {
        insertBack(*i);
    }
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other)
{
    copy(other);
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>&& other) noexcept
{
    if (this != &other)
    {
        clear();
        m_pHead = std::move(other.m_pHead);
        m_pTail = std::move(other.m_pTail);
        m_length = std::move(other.m_length);
    }
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& rhs)
{
    if (this != &rhs)
    {
        clear();
        copy(rhs);
    }
    return *this;
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(SinglyLinkedList<T>&& rhs) noexcept
{
    if (this != &rhs)
    {
        clear();
        m_pHead = std::move(rhs.m_pHead);
        m_pTail = std::move(rhs.m_pTail);
        m_length = std::move(rhs.m_length);
    }
    return *this;
}

template<typename T>
void SinglyLinkedList<T>::copy(const SinglyLinkedList<T>& other)
{
    // set up the default, empty list
    m_pHead = nullptr;
    m_pTail = nullptr;
    m_length = 0;

    // if we have things to copy
    if (!other.empty())
    {
        ListNode* curr = other.m_pHead;
        ListNode* previous = nullptr;
        // iterate down the parameter list
        while (curr != nullptr)
        {
            auto* node = new ListNode(curr->data);

            // set the head of the new list
            if (m_pHead == nullptr)
            {
                m_pHead = node;
            }

            // correct pointer of the previous node if it exists
            if (previous != nullptr)
            {
                previous->next = node;
            }

            previous = node;
            curr = curr->next;
        }

        // prev will contain our new tail---set it up accordingly
        m_pTail = previous;
        m_pTail->next = nullptr;

        m_length = other.m_length;
    }
}

template<typename T>
void SinglyLinkedList<T>::clear()
{
    ListNode* temp = m_pHead;  // points to beginning of linked list
    while (temp != nullptr)
    {
        ListNode* previous = temp;  // holds the past link while we move to the next
        temp = temp->next;          // move onto next link
        delete previous;            // deletes the old link
    }
    m_pTail = nullptr;  // sets tail and head pointers to null
    m_pHead = nullptr;
    m_length = 0;
}

template<typename T>
int SinglyLinkedList<T>::size() const
{
    return m_length;
}

template<typename T>
void SinglyLinkedList<T>::print(std::ostream& os) const
{
    os << "<";
    ListNode* curr = m_pHead;
    while (curr != nullptr)
    {
        os << " " << curr->val;
        if (curr->next != nullptr)
        {
            os << ",";
        }
        curr = curr->next;
    }
    os << " >";
}

template<typename T>
bool SinglyLinkedList<T>::empty() const
{
    return m_pHead == nullptr && m_pTail == nullptr && m_length == 0;
}

template<typename T>
void SinglyLinkedList<T>::insertFront(const T& nData)
{
    auto* node = new ListNode(nData);
    if (m_pHead == nullptr)
    {
        // this is the only node in the list
        node->next = nullptr;
        // now the head and tail point to the new Node
        m_pHead = node;
        m_pTail = m_pHead;
    }
    else
    {
        node->next = m_pHead;  // new Node's next is the second Node
        m_pHead = node;        // head points to the new Node at the front
    }
    m_length++;
}
template<typename T>
void SinglyLinkedList<T>::insertBack(const T& nData)
{
    auto* node = new ListNode(nData);
    if (m_pTail == nullptr)
    {
        // this is the only node in the list
        node->next = nullptr;
        // now the head and tail point to the new Node
        m_pHead = node;
        m_pTail = m_pHead;
    }
    else
    {
        m_pTail->next = node;  // second to last Node's next is the New Node
        m_pTail = node;        // tail points to the new Node at the back
    }
    m_length++;
}

template<typename T>
void SinglyLinkedList<T>::reverse()
{
    // if the list is empty, or has one node in it. then return
    if ((m_pHead == nullptr) || (m_pTail == nullptr) || (m_pHead == m_pTail))
    {
        return;
    }
    ListNode* originalFront = m_pHead;
    ListNode* originalBack = m_pTail;

    // iterate through the list and push pointers onto a stack
    ListNode* itr = m_pHead;
    std::stack<ListNode*> s;
    while (itr != nullptr)
    {
        s.push(itr);
        itr = itr->next;
    }

    // Assign the first pointer on the stack to the head of the list
    itr = m_pHead = s.top();
    ListNode* previous = itr;
    // Now pop from the stack, assigning the next pointers along the way
    while (itr != nullptr)
    {
        s.pop();
        itr = s.top();
        if (s.size() == 1)
        {
            // Assign tail to the last pointer
            m_pTail = itr;
        }
        previous->next = itr;
        previous = previous->next;
    }
}

template<typename T>
SinglyLinkedList<T> SinglyLinkedList<T>::split(int splitPoint)
{
    // split is exceeds the length of the list
    // return an empty list
    if (splitPoint > m_length || splitPoint < 0)
    {
        return SinglyLinkedList<T>();
    }

    //
    ListNode* secondHead = split(m_pHead, splitPoint);

    int originalLength = m_length;
    if (secondHead == m_pHead)
    {
        // if both heads point to the same place then the list is empty
        m_pHead = nullptr;
        m_pTail = nullptr;
        m_length = 0;
    }
    else
    {
        // setup the first list
        // marching through the list and finding the end
        m_pTail = m_pHead;
        while (m_pTail->next != nullptr)
        {
            m_pTail = m_pTail->next;
        }
        // reset the length
        m_length = splitPoint;
    }

    // initialize the second list
    SinglyLinkedList<T> second;
    second.m_pHead = secondHead;
    second.m_pTail = secondHead;
    // finding the second list's tail
    if (second.m_pTail != nullptr)
    {
        while (second.m_pTail->next != nullptr)
        {
            second.m_pTail = second.m_pTail->next;
        }
    }
    second.length_ = originalLength - splitPoint;
    return second;
}

template<typename T>
SinglyLinkedList<T> SinglyLinkedList<T>::split(ListNode* start, int splitPoint)
{
    // empty list edge case
    // if its an empty list then return starting point pointer
    if (start == NULL || splitPoint <= 0)
    {
        return start;
    }
    else
    {
        ListNode* temp1 = m_pHead;
        ListNode* otherTail = nullptr;
        while (splitPoint > 0)
        {
            // move down the list until you get to the startPoint of list 2
            --splitPoint;
            temp1 = temp1->next;
            if (splitPoint == 1)
            {
                // now I am at the end of the other list, I need this pointer to disconnect the two
                // Lists
                otherTail = temp1;
            }
        }
        otherTail->next = nullptr;
        return temp1;
    }
}

template<typename T>
typename SinglyLinkedList<T>::ListNode* SinglyLinkedList<T>::merge(
    SinglyLinkedList::ListNode* first, SinglyLinkedList::ListNode* second)
{
    // two empty lists, return NULL
    if (first == nullptr && second == nullptr)
    {
        return nullptr;
    }
    // merging the same list, results in the same list
    if (first == second)
    {
        return first;
    }
    // if one is empty then return the other
    if (first == nullptr)
    {
        return second;
    }
    if (second == nullptr)
    {
        return first;
    }

    ListNode* returnHead = first;
    ListNode* tempFirst = first;
    ListNode* tempSecond = second;
    ListNode* tempFinal = returnHead;
    // Initializes the pointers before iterating down the lists
    // whichever list has the smaller starting node, place the
    // start of the resulting list there
    if (first->data < second->data)
    {
        tempFirst = first->next;
    }
    else
    {
        returnHead = second;
        tempFinal = returnHead;
        tempSecond = second->next;
    }
    // Now iterate now both lists, extracting the smaller value
    while (tempFirst != nullptr && tempSecond != nullptr)
    {
        if (tempFirst->data < tempSecond->data || tempSecond == nullptr)
        {
            // first's data is smaller, so the final's next points to that data
            tempFinal->next = tempFirst;
            // move the resulting pointer up one up the final list
            tempFinal = tempFinal->next;
            // move the first pointer up one on the first list
            tempFirst = tempFirst->next;
        }
        else
        {
            // second's data is smaller, so the final's next points to that data
            tempFinal->next = tempSecond;
            // move the resulting pointer up one up the final list
            tempFinal = tempFinal->next;
            // move the second pointer up one on the second list
            tempSecond = tempSecond->next;
        }
    }
    // now either the first or second list's pointer points to nullptr
    if (tempFirst == nullptr)
    {
        // now the rest of the final list is what remains of the second list
        tempFinal->next = tempSecond;
    }
    if (tempSecond == nullptr)
    {
        // now the rest of the final list is what remains of the first list
        tempFinal->next = tempFirst;
    }
    return returnHead;
}

template<typename T>
void SinglyLinkedList<T>::mergeWith(SinglyLinkedList<T> const& otherList)
{
    // set up the current list
    m_pHead = merge(m_pHead, otherList.m_pHead);
    m_pTail = m_pHead;

    // make sure there is a node in the new list
    if (m_pTail != nullptr)
    {
        while (m_pTail->next != nullptr)
        {
            m_pTail = m_pTail->next;
        }
    }
    m_length = m_length + otherList.m_length;

    // empty out the parameter list
    otherList.m_pHead = nullptr;
    otherList.m_pTail = nullptr;
    otherList.m_length = 0;
}

template<typename T>
void SinglyLinkedList<T>::sort()
{
    if (m_pHead == nullptr || m_pHead->next == nullptr)
    {
        return;
    }
    ListNode* currHead = m_pHead;
    ListNode *itr, *currMin;
    while (currHead->next != nullptr)
    {
        itr = currHead->next;
        currMin = currHead;
        while (itr != nullptr)
        {
            if (itr->val < currMin->val)
            {
                currMin = itr;
            }
            itr = itr->next;
        }
        T tmp = currHead->val;
        currHead->val = currMin->val;
        currMin->val = tmp;
        currHead = currHead->next;
    }
}

/**
 * \brief Remove duplicate nodes from the linked list, assumes the list is already sorted
 * \tparam T type of the value contained in the linked list
 */
template<typename T>
void SinglyLinkedList<T>::removeDuplicates()
{
    if (m_pHead == nullptr || m_pHead->next == nullptr)
    {
        // base case
        return;
    }

    SinglyLinkedList<T>::ListIterator itr(this->begin());
    while (itr != this->end() && itr.getNode()->next != nullptr)
    {
        // if the current value and the next are the same, skip over the next Node and try again
        if (*itr == *(++itr))
        {
            deleteNode(find(*itr));
        }
    }
}

/**
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked
 * list.You may assume the two numbers do not contain any leading zero, except
 * the number 0 itself.
 * \param
 * \param
 * \return
 */
template<typename T>
SinglyLinkedList<T>* SinglyLinkedList<T>::addTwoNumbers(SinglyLinkedList<T>& l1,
                                                        SinglyLinkedList<T>& l2)
{
    SinglyLinkedList<T>::ListIterator itr1(l1.begin());
    SinglyLinkedList<T>::ListIterator itr2(l2.begin());
    if (itr1 == l1.end() && itr2 == l2.end())
    {
        return nullptr;
    }

    short carryOver = 0;
    auto* ret = new SinglyLinkedList<T>();
    while (itr1 != l1.end() && itr2 != l2.end())
    {
        if (*itr1 + *itr2 + carryOver < 10)
        {
            ret->insertBack(*itr1 + *itr2 + carryOver);
            carryOver = 0;
        }
        else
        {
            short temp = (*itr1 + *itr2 + carryOver);
            ret->insertBack(temp % 10);
            carryOver = (T)temp / 10;
        }
        itr1++;
        itr2++;
    }

    // list2 is longer than list1, copy the remaining values from list2
    if (itr1 == l1.end() && itr2 != l2.end())
    {
        while (itr2 != l2.end())
        {
            ret->insertBack(*itr2);
            itr2++;
        }
    }

    // list1 is longer than list2, copy the remaining values from list1
    if (itr2 == l2.end() && itr1 != l1.end())
    {
        while (itr1 != l1.end())
        {
            ret->insertBack(*itr1);
            itr1++;
        }
    }
    return ret;
}

template<typename T>
T SinglyLinkedList<T>::linkedListToInteger()
{
    // return value
    T ret = 0;
    // exponent value used to march through linked list
    int exponent = 0;
    SinglyLinkedList<int>::ListIterator itr(this->begin());
    // until the end of the list
    while (itr != this->end())
    {
        // Power function is accurately enlarge the current value by the proper
        // power of ten
        ret += (*itr * pow(10, exponent));
        // increment the exponent and move onto the next Node
        exponent++;
        ++itr;
    }
    return ret;
}

/**
 * \brief Convert an integer to a linked list of nodes representing the digits
 *        of the original number
 * @param num Integer to convert to a linked list
 * @return ListNode* to the head of the resulting List
 */
template<typename T>
SinglyLinkedList<T>* SinglyLinkedList<T>::integerToLinkedList(T num)
{
    // save the head of the list to return
    auto* list = new SinglyLinkedList<T>();
    // while the number is not zero
    while (num > 0)
    {
        // create a new node initialized to the last digit in the number to attach
        // to the end of the list
        list->insertFront(num % 10);
        // remove the last digit
        num /= 10;
    }
    return list;
}

/**
 * Given a non-empty, singly linked list with head node head, return a middle
 * node of the linked list. If there are two middle nodes, return the second
 * middle node. O(n) time, O(1) space
 */
template<typename T>
typename SinglyLinkedList<T>::ListNode* SinglyLinkedList<T>::middleNode()
{
    int count = 0;
    ListNode* temp = m_pHead;
    for (; temp != nullptr; temp = temp->next)
    {
        count++;
    }
    count = (count / 2) + 1;
    temp = m_pHead;
    for (int i = 1; i < count; i++)
    {
        temp = temp->next;
    }
    return temp;
}

/**
 * Write a function to delete a node (except the tail) in a singly linked list,
 * given only access to that node. The linked list will have at least two
 * elements. All of the nodes' values will be unique. The given node will not be
 * the tail and it will always be a valid node of the linked list.
 */
template<typename T>
void SinglyLinkedList<T>::deleteNode(SinglyLinkedList<T>::ListIterator deleteNode)
{
    SinglyLinkedList<T>::ListIterator itr(this->begin());
    // Search for the node before the node to delete
    while (itr != this->end())
    {
        if (itr.getNode()->next == deleteNode.getNode())
        {
            // We found the previous node to the one we wish to delete
            break;
        }
        ++itr;
    }
    itr.getNode()->next = deleteNode.getNode()->next;
    delete deleteNode.getNode();
    m_length--;
}

/**
 * \brief insertion sort implementation O(n^2) method
 *
 * \param head Beginning of the linked list to be sorted
 * \return Beginning of the sorted linked list
 */
template<typename T>
typename SinglyLinkedList<T>::ListNode* SinglyLinkedList<T>::insertionSort(ListNode* head)
{
    if (head == nullptr || head->getNext() == nullptr)
        return head;
    ListNode* currHead = head;
    ListNode *itr, *currMin;
    while (currHead->getNext() != nullptr)
    {
        itr = currHead->getNext();
        currMin = currHead;
        while (itr != nullptr)
        {
            if (itr->getVal() < currMin->getVal())
            {
                currMin = itr;
            }
            itr = itr->getNext();
        }
        T tmp = currHead->getVal();
        currHead->setVal(currMin->getVal());
        currMin->setVal(tmp);
        currHead = currHead->getNext();
    }
    return head;
}

template<typename T>
T SinglyLinkedList<T>::sum(SinglyLinkedList<T>::ListIterator itr)
{
    T result {};
    while (itr != ListIterator(nullptr))
    {
        result = result + *itr;
        itr++;
    }
    return result;
}

template<typename T>
typename SinglyLinkedList<T>::ListIterator SinglyLinkedList<T>::find(T searchVal)
{
    SinglyLinkedList::ListIterator itr(m_pHead);
    while (itr != this->end())
    {
        if (*(++itr) == searchVal)
        {
            return itr;
        }
    }
    return SinglyLinkedList<T>::ListIterator();
}
