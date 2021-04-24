#include <iostream>
using namespace std;
#include "helper.h"

template <typename ptr_t>
ptr_t CalcMid_(ptr_t first, ptr_t last, random_access_iterator_tag)
{
    return first + (last - first) / 2;
}

// bidirectional iterator
template <typename ptr_t>
ptr_t CalcMid_(ptr_t first, ptr_t last, bidirectional_iterator_tag)
{
    while (first != last && first != --last)
    {
        ++first;
    }
    return first;
}
// input iterator
template <typename ptr_t>
ptr_t CalcMid_(ptr_t first, ptr_t last, input_iterator_tag)
{
    ptr_t temp(*first);
    while (first != last && ++first != last)
    {
        ++temp;
        ++first;
    }
    return temp;
}

template <typename ptr_t>
ptr_t CalcMid(ptr_t first, ptr_t last)
{
    return CalcMid_(first, last,
                    typename iterator_traits<ptr_t>::iterator_category());
}

// Difference Helpers
template <typename ptr_t>
int CalcDiff_(ptr_t first, ptr_t last, input_iterator_tag)
{

    int i = 0;

    while (first != end)
    {
        i += 1;
        ++first;
    }

    return i;
}

template <typename ptr_t>
int CalcDiff_(ptr_t first, ptr_t last, bidirectional_iterator_tag)
{
    return last - first;
}

template <typename ptr_t>
int CalcDiff_(ptr_t first, ptr_t last, random_access_iterator_tag)
{
    return last - first;
}

template <typename ptr_t>
int CalcDiff(ptr_t first, ptr_t last)
{
    return CalcDiff_(first, last, typename iterator_traits<ptr_t>::iterator_category());
}