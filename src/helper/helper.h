#ifndef HELPER_H

#define HELPER_H

// Random Access iterator
template<typename ptr_t>
ptr_t CalcMid_(ptr_t first, ptr_t last, random_access_iterator_tag);

// bidirectional iterator
template<typename ptr_t>
ptr_t CalcMid_(ptr_t first, ptr_t last, bidirectional_iterator_tag);

// input iterator
template<typename ptr_t>
ptr_t CalcMid_(ptr_t first, ptr_t last, input_iterator_tag);

template<typename ptr_t>
ptr_t CalcMid(ptr_t first, ptr_t last);




template <typename ptr_t>
int CalcDiff_(ptr_t first, ptr_t last, input_iterator_tag);

template <typename ptr_t>
int CalcDiff_(ptr_t first, ptr_t last, bidirectional_iterator_tag);

template <typename ptr_t>
int CalcDiff_(ptr_t first, ptr_t last, random_access_iterator_tag);

template <typename ptr_t>
int CalcDiff(ptr_t first, ptr_t last);

#endif