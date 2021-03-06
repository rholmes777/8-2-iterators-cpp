//
//  main.cpp
//  8-2-iterators-impl
//
//  Created by Richard Holmes on 1/28/13.
//  Copyright (c) 2013 Richard Holmes. All rights reserved.
//
//  Implement our own versions of the following library algorithms,
//  per exercise 8-2 in Accelerated C++ (Moo, Koenig)
//      equal(b, e, b2)
//      find(b, e, t)
//      copy(b, e, d)
//      remove_copy_if(b, e, d, p)
//      transform(b, e, d f)
//      accumulate(b, e, t)
//      search(b, e, b2, e2)
//      find_if(b, e, p)
//      remove_copy(b, e, d, t)
//      remove(b, e, t)
//      partition(b, e, p)
//



#include <iostream>
#include <vector>
#include "IteratorAlgorithms.h"

int main(int argc, const char * argv[])
{
    // We could use our algorithms here, or just test in google test...

    // Try to print the vector out (NOTE: Doesn't work in g++ 4.7)
    //std::vector<int> v({1, 2, 3});
    //std::cout << "Print a vector using iostream: " << v << std::endl;
    std::cout << "Print a vector using iostream: doesn't compile in g++ 4.7/Ubuntu" << std::endl;

    return 0;
}

