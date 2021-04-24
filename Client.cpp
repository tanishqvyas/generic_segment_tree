#include <iostream>
using namespace std;
#include <vector>
#include "./src/SegmentTree.cpp"
#include <limits.h>

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



struct Up{

    int operator()(int a){
        return a;
    }

};

int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4,5};

    vector<int>::iterator it;

    seg_tree<vector<int>::iterator, Add, Up> s(begin(v), end(v) - 1, v.size());

    cout<<s<<"\n";
    
    s.update(begin(v),begin(v),end(v)-1,1,3,0,6);

    cout<<s<<"\n";

    auto val = s.query(v.begin(), v.begin(), end(v) - 1, 1, 4, 0);
    cout << val << " ---\n";

    return 0;
}
