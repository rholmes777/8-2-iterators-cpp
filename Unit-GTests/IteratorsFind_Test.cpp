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
TEST(Find, NotFoundInEmptyList)
{
    std::vector<int> vecA;
    std::vector<int>::const_iterator it = Namespace::find(vecA.begin(), vecA.end(), 3);

    EXPECT_EQ(it, vecA.end());
}

TEST(Find, FoundIfOnlyElementMatches)
{
    std::vector<int> vectorA = {1};
    
    EXPECT_EQ(Namespace::find(vectorA.begin(), vectorA.end(), 1), vectorA.begin());
}

TEST(Find, NotFoundIfOnlyElementDoesntMatch)
{
    std::vector<int> vectorA = {1};
    std::vector<int>::iterator it = Namespace::find(vectorA.begin(), vectorA.end(), 3);
    EXPECT_NE(it, vectorA.begin());
    EXPECT_EQ(it, vectorA.end());
}

TEST(Find, FoundIfElementMatches)
{
    std::vector<int> vectorA = {3, 5, 7, 9, 11, 25, 30, 35};
    std::vector<int>::iterator it = Namespace::find(vectorA.begin(), vectorA.end(), 9);
    EXPECT_EQ(it, vectorA.begin()+3);
}

TEST(Find, NotFoundIfElementDoesntMatch)
{
    std::vector<int> vectorA = {3, 5, 7, 9, 11, 25, 30, 35};    
    std::vector<int>::iterator it = Namespace::find(vectorA.begin(), vectorA.end(), -12);
    EXPECT_EQ(it, vectorA.end());
}

TEST(Find, FoundIfElementMatches_List)
{
    std::list<int> listA = {3, 5, 7, 9, 11, 25, 30, 35};
    std::list<int>::iterator it = Namespace::find(listA.begin(), listA.end(), 9);
    EXPECT_EQ(*it, 9);
    
    // increment iterator to the known element
    auto index = listA.begin();
    index++; index++; index++;
    EXPECT_EQ(it, index);
}

TEST(Find, NotFoundIfElementDoesntMatch_List)
{
    std::list<int> listA = {3, 5, 7, 9, 11, 25, 30, 35};
    std::list<int>::iterator it = Namespace::find(listA.begin(), listA.end(), -12);
    EXPECT_EQ(it, listA.end());
}
