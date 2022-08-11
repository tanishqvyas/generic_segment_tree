#include <iostream>
using namespace std;
#include <vector>
#include "SegmentTree.h"
#include "./helper/helper.cpp"

// Implementation file for Generic Segment Tree Library.


//Create Seg Tree Function
template <typename ptr_t, typename functor>
seg_tree<ptr_t, functor>::seg_tree(ptr_t start, ptr_t end, int size) : size_(2 * size - 1)
{
    // Initializing empty tree with all  nodes with a value of 0
    myTree.assign(size_, functor()());

    // Call Create Segment Tree Function
    CreateSegTree_(start, end, 0);
}

template <typename ptr_t, typename functor>
seg_tree<ptr_t, functor>::seg_tree(seg_tree &s)
{

    this->myTree.assign(s.size_, functor()());
    this->size_ = s.size_;
    // cout<<s.size_<<" ---\n";
    for (int i = 0; i < this->size_; i++)
    {
        this->myTree[i] = s.myTree[i];
    }
}

template <typename ptr_t, typename functor>
void seg_tree<ptr_t, functor>::CreateSegTree_(ptr_t start, ptr_t end, int node)
{
    // Base condition
    if (start == end)
    {
        myTree[node] = *start;
        //cout << myTree[node] << " --\n";
        return;
    }

    // Find the mid
    ptr_t mid = CalcMid(start, end);

    // cout<<*mid<<"\n";
    // Compute valuesfor children
    CreateSegTree_(start, mid, 2 * node + 1);
    CreateSegTree_(mid + 1, end, 2 * node + 2);

    myTree[node] = functor()(myTree[2 * node + 1], myTree[2 * node + 2]);
    // cout<<myTree[node]<<"\n";
}

//Update Function
template <typename ptr_t, typename functor>
template <typename up_functor>
void seg_tree<ptr_t, functor>::update(const ptr_t head, ptr_t start, ptr_t end, int l, int r, int node, data_type val, up_functor update_functor)
{

    int s_to_h = CalcDiff(head, start);
    int e_to_h = CalcDiff(head, end);
    if (s_to_h > e_to_h || s_to_h > r || e_to_h < l)
    {
        return;
    }

    if (start == end)
    {

        myTree[node] = update_functor(myTree[node], val);
        return;
    }

    ptr_t mid = CalcMid(start, end);

    update(head, start, mid, l, r, 2 * node + 1, val, update_functor);

    update(head, mid + 1, end, l, r, 2 * node + 2, val, update_functor);

    myTree[node] = functor()(myTree[2 * node + 1], myTree[2 * node + 2]);
}

// Query Functions
template <typename ptr_t, typename functor>
typename seg_tree<ptr_t, functor>::data_type seg_tree<ptr_t, functor>::query(const ptr_t head, ptr_t start, ptr_t end, int L, int R, int node)
{
    int s_to_h = CalcDiff(head, start);
    int e_to_h = CalcDiff(head, end);
    //cout<<L<<" --- "<<R<<"\n";
    if (R < s_to_h || (e_to_h < L))
    {
        return functor()();
    }

    if (L <= s_to_h && R >= (e_to_h))
    {
        return myTree[node];
    }

    ptr_t mid = CalcMid(start, end);

    data_type left = query(head, start, mid, L, R, 2 * node + 1);
    data_type right = query(head, mid + 1, end, L, R, 2 * node + 2);

    return functor()(left, right);
}
