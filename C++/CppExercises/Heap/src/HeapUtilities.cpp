//
// Created by Michael Anthony Pope on 6/22/21.
//

#include "HeapUtilities.h"
#include <algorithm>

/**
 * \brief We have a collection of stones, each stone has a positive integer weight. Each turn, we
 * choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y
 * with x <= y.  The result of this smash is:
 *      If x == y, both stones are totally destroyed;
 *      If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new
 *      weight y-x.
 * At the end, there is at most 1 stone left. Return the weight of this stone (or 0 if there are no
 * stones left.) LeetCode Problem 1046.
 * \param stones Input vector of stones to process
 * \note O(n) runtime, O(1) space
 * \return the value of the last stone left as described by the problem
 */
int HeapUtilities::lastStoneWeight(std::vector<int>& stones)
{
    std::make_heap(stones.begin(), stones.end(), std::less<>{});
    while(stones.size() > 1)
    {
        // pop the first stone from the heap
        std::pop_heap(stones.begin(), stones.end(), std::less<>{});
        auto top1 = stones.back();
        stones.pop_back();
        // pop the second stone from the heap
        std::pop_heap(stones.begin(), stones.end(), std::less<>{});
        auto top2 = stones.back();
        stones.pop_back();

        // if the stones are unequal, one smashes the other. Otherwise they annihilate
        if (top1 != top2)
        {
            // add a new stone to the heap which is the difference of the two stones
            stones.push_back(top1 - top2);
            std::push_heap(stones.begin(), stones.end(), std::less<>{});
        }
    }
    // the vector may be "empty", the underlying data still remains.
    if (stones.empty())
    {
        return 0;
    }
    else
    {
        return stones.front();
    }
}