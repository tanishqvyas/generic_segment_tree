#include <iostream>
#include <vector>
#include "./src/segTree.h"

using namespace std;

/*

This class shows on how to use the library and depicts
an addition example on a vector and how to perfrom 
updates and range queries.

*/


int main(int argc, char const *argv[])
{
     vector<int> v = {1, 2, 3, 4, 5};

     vector<int>::iterator it;

     seg_tree<vector<int>::iterator, Add<int>> s(begin(v), end(v) - 1, v.size());

     int l1 = 1;
     int r1 = 2;
     int l2 = 3;
     int r2 = 4;

     seg_tree<vector<int>::iterator, Add<int>> s1(s);

     cout << s1 << " -----\n";
     
     //void update(const ptr_t head, ptr_t start, ptr_t end, int l, int r, int node, data_type val, up_functor update_functor);

     s1.update(begin(v), begin(v), end(v) - 1, l1, r1, 0, 6, addEq<int>());

     // 1 8 9 4 5 = 27

     cout << "Updated Segment Tree for += 6 --> \n"
          << s1 << "\n";

     s1.update(begin(v), begin(v), end(v) - 1, l2, r2, 0, 4, Eq<int>());

     // 1 8 9 4 4 = 26

     cout << "Updated Segment Tree for assiginig value 4 ---> \n"
          << s1 << "\n";

     int l3 = 1;
     int r3 = 4;

     //data_type query(const ptr_t head, ptr_t start, ptr_t end, int L, int R, int node);
     
     auto val = s1.query(v.begin(), v.begin(), end(v) - 1, l3, r3, 0);
     cout << val << "\n";

     return 0;
}
