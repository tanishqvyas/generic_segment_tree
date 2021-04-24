#include "./SegmentTree.cpp"
#include <limits.h>

/* QUERY FUNCTORS */

template <typename T1, typename T2 = T1>
struct Add
{
    T2 operator()()
    {
        return 0;
    }

    T2 operator()(T1 a, T1 b) { return a + b; }
};

template <typename T1, typename T2 = T1>
struct Mul
{
    T2 operator()()
    {
        return 1;
    }

    T2 operator()(T1 a, T1 b) { return a * b; }
};

template <typename T1, typename T2 = T1>
struct Max
{
    T2 operator()()
    {
        return INT_MIN;
    }

    T2 operator()(T1 a, T1 b)
    {
        return max(a, b);
    };
};

template <typename T1, typename T2 = T1>
struct Min
{
    T2 operator()()
    {
        return INT_MAX;
    }

    T2 operator()(T1 a, T1 b)
    {
        return min(a, b);
    };
};

/* UPDATE FUNCTORS */
template <typename T1, typename T2 = T1>
struct Eq
{
    int operator()(int myTree, int a)
    {
        return a;
    }
};

template <typename T1, typename T2 = T1>
struct addEq
{
    T2 operator()(T1 myTree, T1 val)
    {
        return myTree + val;
    }
};

template <typename T1, typename T2 = T1>
struct subEq
{
    T2 operator()(T1 myTree, T1 val)
    {
        return myTree - val;
    }
};

template <typename T1, typename T2 = T1>
struct subEqRev
{
    T2 operator()(T1 myTree, T1 val)
    {
        return val - myTree;
    }
};

template <typename T1, typename T2 = T1>
struct mulEq
{
    T2 operator()(T1 myTree, T1 val)
    {
        return myTree * val;
    }
};

template <typename T1, typename T2 = T1>
struct modEq
{
    T2 operator()(T1 myTree, T1 val)
    {
        return myTree % val;
    }
};
