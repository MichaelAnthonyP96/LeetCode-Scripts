//
//  SinglyLinkedList.hpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#ifndef SinglyLinkedList_hpp
#define SinglyLinkedList_hpp

#include <cstdio>

#include "ListADT.hpp"

template<typename T>
class SinglyLinkedList : public ListADT<T>
{
  private:
    struct ListNode
    {
        ListNode();
        explicit ListNode(const T& x);  // constructor
        ListNode(T x, ListNode* next);  // constructor
        virtual ~ListNode();            // destructor

        ListNode* next;  // ListNode pointer next
        T val;           // Value
    };

    ListNode* m_pHead;
    ListNode* m_pTail;
    size_t m_length;

  public:
    // "Rule of Six" functions
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList<T>& other);
    SinglyLinkedList(const SinglyLinkedList<T>&& other) noexcept;
    SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>& rhs);
    SinglyLinkedList<T>& operator=(SinglyLinkedList<T>&& rhs) noexcept;
    ~SinglyLinkedList();

    // Abstract Data Type function to fulfill
    [[nodiscard]] bool empty() const override;
    [[nodiscard]] int size() const override;
    void print(std::ostream& os) const override;
    void insertFront(const T& nData) override;
    void sort() override;

    class ListIterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
        ListNode* p;

      public:
        ListIterator();
        explicit ListIterator(ListNode* x);

        // Pre-Increment
        ListIterator& operator++();
        // Post-Increment
        const ListIterator operator++(int);
        bool operator==(const ListIterator& rhs);
        bool operator!=(const ListIterator& rhs);
        const T& operator*();
        const T* operator->();
        ListNode*& getNode();
    };
    typedef ListIterator iterator;
    typedef ListIterator const_iterator;

    const_iterator begin() const
    {
        return ListIterator(m_pHead);
    }
    const_iterator end() const
    {
        return ListIterator(nullptr);
    }

    friend ListNode *& ListIterator::getNode();
    // Iterator constructor
    template<class Iter>
    SinglyLinkedList(const Iter& start, const Iter& end);

    // Helper methods
    void copy(SinglyLinkedList<T> const& other);
    void clear();
    void insertBack(const T& nData);
    void reverse();
    SinglyLinkedList<T> split(int splitPoint);
    SinglyLinkedList<T> split(ListNode* start, int splitPoint);
    SinglyLinkedList<T>::ListNode* merge(ListNode* first, ListNode* second);
    void mergeWith(SinglyLinkedList<T> const& otherList);
    void append(SinglyLinkedList<T> const& otherList);

    // Utility methods to operate on the list
    void removeDuplicates();
    static SinglyLinkedList<T>* addTwoNumbers(SinglyLinkedList<T>& l1, SinglyLinkedList<T>& l2);
    T linkedListToInteger();
    static SinglyLinkedList<T>* integerToLinkedList(T num);
    ListNode* middleNode();
    ListIterator find(T searchVal);
    void deleteNode(SinglyLinkedList<T>::ListIterator itr);
    static ListNode* insertionSort(ListNode* head);
    static T sum(SinglyLinkedList<T>::ListIterator itr);
    static ListNode* getIntersectionNode(SinglyLinkedList<T>& lA, SinglyLinkedList<T>& lB);
    static bool hasCycle(SinglyLinkedList<T>& l);
  private:
    static ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
    static bool hasCycle(ListNode* head);
};

#include "SinglyLinkedList.cpp"
#endif  // SinglyLinkedList_hpp
