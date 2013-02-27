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

}
#endif
