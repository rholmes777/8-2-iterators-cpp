//
//  IteratorsEqual_Test.cpp
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
TEST(Equal, EmptyListsShouldBeEqual)
{
    std::vector<int> vectorA, vectorB;
    
    EXPECT_TRUE(Namespace::equal(vectorA.begin(), vectorA.end(), vectorB.begin()));
}

TEST(Equal, ContainersWithSameSingleValueShouldBeEqual)
{
    std::vector<int> vectorA = {1};
    std::list<int> listB = {1};
    
    EXPECT_TRUE(Namespace::equal(vectorA.begin(), vectorA.end(), listB.begin()));
}

TEST(Equal, ContainersWithDifferentSingleValueShouldBeNotEqual)
{
    std::vector<int> vectorA = {3};
    std::list<int> listB = {1};
    
    EXPECT_FALSE(Namespace::equal(vectorA.begin(), vectorA.end(), listB.begin()));
}

TEST(Equal, EqualityOfSubrangeDetected_A)
{
    std::vector<int> vectorA = {3, 5, 7, 9, 11, 25, 30, 35};
    std::vector<int> vectorB = {-1, -2, 25, 30, -3};
    
    EXPECT_TRUE(Namespace::equal(vectorA.begin()+5, vectorA.begin()+7, vectorB.begin()+2));
}

TEST(Equal, NonEqualityOfSubrangeDetected_A)
{
    std::vector<int> vectorA = {3, 5, 7, 9, 11, 25, 30, 35};
    std::vector<int> vectorB = {-1, -2, 25, -3, -3};
    
    EXPECT_FALSE(Namespace::equal(vectorA.begin()+5, vectorA.begin()+7, vectorB.begin()+2));
}

TEST(Equal, NonEqualityOfSubrangeDetected_B)
{
    std::vector<int> vectorA = {3, 5, 7, 9, 11, 25, 30, 35};
    std::list<int> listB = {-1, -2, 25, -3, -3};
    
    auto listB_iterator = listB.begin();
    listB_iterator++;
    listB_iterator++;
    
    EXPECT_FALSE(Namespace::equal(vectorA.begin()+5, vectorA.begin()+7, listB_iterator));
}

TEST(Equal, NonEqualityOfSubrangeDetected_NotEnoughElementsInSecondRange)
{
    std::vector<int> vectorA = {3, 5, 7, 9, 11, 25, 30, 35};
    std::vector<int> vectorB = {-1, -2, 25};
    
    EXPECT_FALSE(Namespace::equal(vectorA.begin()+5, vectorA.begin()+7, vectorB.begin()+2));
}

/////////////////////////////////////////////////////////////////////////////////////////////

// Sloppy predicate, second argument can be off by one in either direction for integral type
bool sloppyPredicate(int a, int b)
{
    return a==b || a==(b-1) || a==(b+1);
}
// Sloppy predicate, second argument can be off by slop in either direction
bool sloppyPredicate(float a, float b)
{
    const float tolerance = 0.5;
    return a > b-tolerance && a < b+tolerance;
}

TEST(EqualPred, EqualSingleValueSloppyIntPredicate)
{
    std::vector<int> vectorA = {2};
    std::vector<int> vectorB = {1};
    
    EXPECT_TRUE(Namespace::equal(vectorA.begin(), vectorA.end(), vectorB.begin(), sloppyPredicate));
}

TEST(EqualPred, NotEqualSingleValueSloppyIntPredicate)
{
    std::vector<int> vectorA = {3};
    std::vector<int> vectorB = {1};
    
    EXPECT_FALSE(Namespace::equal(vectorA.begin(), vectorA.end(), vectorB.begin(), sloppyPredicate));
}

TEST(EqualPred, EqualSingleValueSloppyFloatPredicate)
{
    std::vector<float> vectorA = {3.2};
    std::vector<float> vectorB = {3};
    
    EXPECT_TRUE(Namespace::equal(vectorA.begin(), vectorA.end(), vectorB.begin(), sloppyPredicate));
}

TEST(EqualPred, NotEqualSingleValueSloppyFloatPredicate)
{
    std::vector<float> vectorA = {3.7};
    std::vector<float> vectorB = {3};
    
    EXPECT_FALSE(Namespace::equal(vectorA.begin(), vectorA.end(), vectorB.begin(), sloppyPredicate));
}


