#include <iostream>
using namespace std;
#include <vector>
#include "./src/segTree.h"

/*

This class shows on how to use the library and depicts
an addition example on a vector and how to perfrom
updates and range queries.

*/

// Following code contians example of getting susbstring of a string using segment trees
template <typename T1, typename T2 = T1>
struct str
{

    T2 operator()()
    {
        return "";
    }

    T2 operator()(T1 a, T1 b)
    {
        return a + b;
    }
};

template <typename T1, typename T2 = T1>
struct up_str
{
    string operator()(string myTree, string a)
    {
        return a;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 4, 5};

    vector<int>::iterator it;

    string s1 = "this_is_our_gp_review";
    seg_tree<string::iterator, str<string>> s(begin(s1), end(s1) - 1, s1.size());

    int l1 = 16;
    int r1 = 18;

    // //void update(const ptr_t head, ptr_t start, ptr_t end, int l, int r, int node, data_type val, up_functor update_functor);

    s.update(begin(s1), begin(s1), end(s1) - 1, l1, r1, 0, "X", up_str<string>());

    int l3 = 14;
    int r3 = 20;

    // data_type query(const ptr_t head, ptr_t start, ptr_t end, int L, int R, int node);

    auto val = s.query(s1.begin(), s1.begin(), end(s1) - 1, l3, r3, 0);
    cout << val << "\n";

    return 0;
}
