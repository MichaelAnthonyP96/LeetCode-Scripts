//
// Created by Michael Anthony Pope on 6/22/21.
//

#include "gtest/gtest.h"
#include "HeapUtilities.h"

TEST(lastStoneWeight, annihilate)
{
    std::vector<int> v {2, 2};
    ASSERT_EQ(0, HeapUtilities::lastStoneWeight(v));
}

TEST(lastStoneWeight, process)
{
    std::vector<int> v {2, 7, 4, 1, 8, 1};
    ASSERT_EQ(1, HeapUtilities::lastStoneWeight(v));
}

TEST(lastStoneWeight, empty)
{
    std::vector<int> v {};
    ASSERT_EQ(0, HeapUtilities::lastStoneWeight(v));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}