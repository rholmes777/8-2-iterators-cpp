//
//  Header.h
//  8-2-iterators-impl
//
//  Created by Richard Holmes on 2/24/13.
//  Copyright (c) 2013 Richard Holmes. All rights reserved.
//

#ifndef __2_iterators_impl_IteratorAlgorithms_h
#define __2_iterators_impl_IteratorAlgorithms_h

namespace rah {
    
    //////////////////////////
    // Equal
    //////////////////////////    
    template<class InputIterator_T1, class InputIterator_T2>
    bool equal(InputIterator_T1 begin1, InputIterator_T1 end1, InputIterator_T2 begin2)
    {
        for ( ; begin1 != end1; begin1++, begin2++) {
            if (*begin1 != *begin2)
            {
                return false;
            }
        }
        return true;
    }

    template<class InputIterator_T1, class InputIterator_T2>
    bool equal(InputIterator_T1 begin1, InputIterator_T1 end1, InputIterator_T2 begin2,
               bool pred(typename InputIterator_T1::value_type, typename InputIterator_T2::value_type))
    {
        for ( ; begin1 != end1; begin1++, begin2++) {
            if ( ! pred(*begin1, *begin2) )
            {
                return false;
            }
        }
        return true;
    }
    
    //////////////////////////
    // Find
    //////////////////////////
    template<class InputIterator_T1>
    InputIterator_T1 find(InputIterator_T1 begin1, InputIterator_T1 end1, typename InputIterator_T1::value_type toFind)
    {
        while (begin1 != end1)
        {
            if (*begin1 == toFind)
            {
                return begin1;
            }
            begin1++;
        }
        return end1;
    }

    //////////////////////////
    // Copy: Copies the elements in the range [first,last) into the range beginning at result.
    //////////////////////////
    template<class InputIterator_T, class OutputIterator_T>
    OutputIterator_T copy(InputIterator_T first, InputIterator_T last, OutputIterator_T result)
    {
        while (first != last)
        {
            *result = *first;
            result++;
            first++;
        }
        return result;
    }

    //////////////////////////
    // remove_copy_if: Copies the elements in the range [first,last) into the range beginning at result.
    //////////////////////////
    template<class InputIterator_T, class OutputIterator_T>
    OutputIterator_T remove_copy_if(InputIterator_T first, InputIterator_T last, OutputIterator_T result,
                          bool pred(typename InputIterator_T::value_type item))
    {
        while (first != last)
        {
            if ( ! pred(*first) )
            {
                *result = *first;
                result++;
            }
            first++;
        }
        return result;
    }


}
#endif
