#include <iostream>
using namespace std;
#include<vector>
// #include "./src/SegmentTree.h"
#include "./src/SegmentTree.cpp"

int main(int argc, char const *argv[])
{

    vector<int>v = {1,2, 3, 4, 5};

    vector<int>::iterator it;

    seg_tree<vector<int>::iterator>s(begin(v),end(v)-1, v.size());
    
    cout<<s;


    return 0;
}
