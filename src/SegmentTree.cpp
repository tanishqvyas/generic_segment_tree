#include<iostream>
using namespace std;
#include<vector>
#include "SegmentTree.h"
#include "./helper/helper.cpp"

template<typename ptr_t>
seg_tree<ptr_t>::seg_tree(ptr_t start, ptr_t end, int size):size_(2*size-1)
{
    // Initializing empty tree with all  nodes with a value of 0
    myTree.assign(size_, 0);

    // Call Create Segment Tree Function
    CreateSegTree_(start, end, 0);
}



template<typename ptr_t>
void seg_tree<ptr_t>::CreateSegTree_(ptr_t start, ptr_t end, int node)
{
    // Base condition ----------------->
    if(start == end)
    {
        myTree[node] = *start;
        return;
    }


    // Recursive condition ------------>

    // Find the mid
    ptr_t mid = CalcMid(start, end);
    // Compute valuesfor children
    CreateSegTree_(start,mid,2*node+1);
    CreateSegTree_(mid+1,end,2*node+2);


    myTree[node] = myTree[2*node + 1] + myTree[2*node + 2];

}




