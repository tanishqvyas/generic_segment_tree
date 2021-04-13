#include <iostream>
using namespace std;
#include <vector>
// #include "./src/SegmentTree.h"
#include "./src/SegmentTree.cpp"
#include <limits.h>
// template<typename T>
struct Add
{
    int operator()()
    {
        return 0;
    }

    int operator()(int a, int b) { return a + b; }
};

struct Mul
{
    int operator()()
    {
        return 1;
    }

    int operator()(int a, int b) { return a * b; }
};

struct MaxNumber
{
    int operator()()
    {
        return INT_MIN;
    }

    int operator()(int a, int b)
    {
        return max(a, b);
    };
};

struct MinNumber
{
    int operator()()
    {
        return INT_MAX;
    }

    int operator()(int a, int b)
    {
        return min(a, b);
    };
};


int main(int argc, char const *argv[])
{
    vector<int> v = {-10, -9, -1, -3, -3};

    vector<int>::iterator it;

    seg_tree<vector<int>::iterator, Add> s(begin(v), end(v) - 1, v.size());

    auto val = s.query(v.begin(), v.begin(), end(v) - 1, 1, 4, 0);

    cout << val << "\n";

    return 0;
}
