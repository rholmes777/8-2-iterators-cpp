//
//  IteratorsFind_Test.cpp
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


/////////////////////////////////////////////////////////////////////////////////////////////
bool truePred(int)   { return true; }
bool falsePred(int)  { return false; }
bool evenPred(int i) { return i%2 == 0; }
bool oddPred(int i)  { return i%2; }

/////////////////////////////////////////////////////////////////////////////////////////////
TEST(RemoveCopyIf, CopyAllIfPredFalse)
{
    std::vector<int> sourceVec({1, 2, 3, 4, 5});
    std::vector<int> targetVec(5);

    auto iter = Namespace::remove_copy_if(sourceVec.begin(), sourceVec.end(), targetVec.begin(), falsePred);

    EXPECT_EQ(targetVec.begin()+5, iter) << "Return value should point after the copied 5 items.";
    EXPECT_EQ(std::vector<int>({1, 2, 3, 4, 5}), targetVec);
}

TEST(RemoveCopyIf, CopyNoneIfPredTrue)
{
    std::vector<int> sourceVec({1, 2, 3, 4, 5});
    std::vector<int> targetVec(5);

    auto iter = Namespace::remove_copy_if(sourceVec.begin(), sourceVec.end(), targetVec.begin(), truePred);

    EXPECT_EQ(targetVec.begin(), iter) << "Return value should point after the copied 5 items.";
    EXPECT_EQ(std::vector<int>({0, 0, 0, 0, 0}), targetVec);
}

TEST(RemoveCopyIf, CopyOddNumbers)
{
    std::vector<int> sourceVec({1, 2, 3, 4, 5});
    std::vector<int> targetVec(5);

    auto iter = Namespace::remove_copy_if(sourceVec.begin(), sourceVec.end(), targetVec.begin(), evenPred);

    EXPECT_EQ(targetVec.begin()+3, iter) << "Return value should point after the copied 3 items.";
    EXPECT_EQ(std::vector<int>({1, 3, 5, 0, 0}), targetVec);
}

TEST(RemoveCopyIf, CopyEvenNumbers)
{
    std::vector<int> sourceVec({1, 2, 3, 4, 5});
    std::vector<int> targetVec(5);

    auto iter = Namespace::remove_copy_if(sourceVec.begin(), sourceVec.end(), targetVec.begin(), oddPred);

    EXPECT_EQ(targetVec.begin()+2, iter) << "Return value should point after the copied 2 items.";
    EXPECT_EQ(std::vector<int>({2, 4, 0, 0, 0}), targetVec);
}


