//
// Created by Michael Anthony Pope on 2/28/21.
//

#ifndef CPPEXERCISES_VERSION_2_1_0_LINKEDLIST_INCLUDE_LISTADT_H_
#define CPPEXERCISES_VERSION_2_1_0_LINKEDLIST_INCLUDE_LISTADT_H_

#include <iostream>

template<typename T>
class ListADT
{
  public:
    virtual ~ListADT() = default;
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void insertFront(const T& nData) = 0;
    virtual void sort() = 0;
};

#endif  // CPPEXERCISES_VERSION_2_1_0_LINKEDLIST_INCLUDE_LISTADT_H_
