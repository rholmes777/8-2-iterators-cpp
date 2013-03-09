//
//  IteratorsCopy_Test.cpp
//  Unit-GTests
//
//  Created by Richard Holmes on 2/18/13.
//  Copyright (c) 2013 Richard Holmes. All rights reserved.

#include "gtest/gtest.h"

#include "IteratorAlgorithms.h"
#include <algorithm>
#include <vector>
#include <list>

#define Namespace rah
//#define Namespace std

// TODO iterator comparisons will crash with symbol not found when Google Test tries to print
// the arguments to the failed expectation.  Fix this...

/////////////////////////////////////////////////////////////////////////////////////////////
TEST(Copy, CopyEmptyRangeDoesntChangeResult_1)
{
    std::vector<int> vecA;
    std::vector<int> vecB = {3};
    
    std::vector<int>::iterator it = Namespace::copy(vecA.begin(), vecA.end(), vecB.begin());

    EXPECT_EQ(vecB.begin(), it);
}

TEST(Copy, CopyEmptyRangeDoesntChangeResult_2)
{
    std::vector<int> vecA = {1, 2, 3};
    std::vector<int> vecB = {3};
    
    std::vector<int>::iterator it = Namespace::copy(vecA.begin()+1, vecA.begin()+1, vecB.begin());
    
    EXPECT_EQ(vecB.begin(), it);
    EXPECT_EQ(std::vector<int>({3}), vecB);
}

TEST(Copy, CopyOneElementToEmptyContainer)
{
    std::vector<int> vecA = {1, 2, 3};
    std::vector<int> vecB(1);
    
    std::vector<int>::iterator it = Namespace::copy(vecA.begin()+1, vecA.begin()+2, vecB.begin());
    EXPECT_EQ(vecB.end(), it);
    EXPECT_TRUE(std::equal(vecB.begin(), vecB.end(), std::vector<int>({2}).begin()));
}


TEST(Copy, CopyMultipleElementsToEmptyContainer)
{
    std::vector<int> vecA = {1, 2, 3};
    std::vector<int> vecB(3);
    
    std::vector<int>::iterator it = Namespace::copy(vecA.begin(), vecA.end(), vecB.begin());
    EXPECT_EQ(vecB.end(), it);

    std::vector<int> reference = {1, 2, 3};
    EXPECT_TRUE(std::equal(vecB.begin(), vecB.end(), reference.begin()));
}

TEST(Copy, CopyMultipleElementsToBeginningOfContainer)
{
    std::vector<int> vecA = {1, 2, 3};
    std::vector<int> vecB(3);
    vecB = {4, 5, 0};
    
    std::vector<int>::iterator it = Namespace::copy(vecA.begin(), vecA.end(), vecB.begin());
    EXPECT_EQ(vecB.end(), it);
    EXPECT_TRUE(std::equal(vecB.begin(), vecB.end(), std::vector<int>({1, 2, 3}).begin()));
    EXPECT_EQ(std::vector<int>({1, 2, 3}), vecB);
}


