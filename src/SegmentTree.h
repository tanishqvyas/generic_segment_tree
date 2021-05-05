#ifndef SEGMENT_TREE_H

#define SEGMENT_TREE_H

template <typename ptr_t, typename functor>
class seg_tree
{

private:
    typedef decltype(functor()()) data_type;

    int size_;
    vector<data_type> myTree;

    void CreateSegTree_(ptr_t start, ptr_t end, int node);

public:
    seg_tree(ptr_t first, ptr_t last, int size);
    seg_tree(seg_tree &s);

    friend ostream &operator<<(ostream &o, const seg_tree<ptr_t, functor> &s)
    {
        for (int i = 0; i < s.size_; i++)
        {
            o << s.myTree[i] << "\t";
        }
        cout << "\n";

        return o;
    }

    data_type query(const ptr_t head, ptr_t start, ptr_t end, int L, int R, int node);

    template <typename up_functor>
    void update(const ptr_t head, ptr_t start, ptr_t end, int l, int r, int node, data_type val, up_functor update_functor);
};

#endif
