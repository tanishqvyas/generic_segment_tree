#ifndef SEGMENT_TREE_H

#define SEGMENT_TREE_H

template <typename ptr_t, typename functor>
class seg_tree
{

private:
    typedef decltype(functor()()) data_type;

    // Data
    int size_;
    vector<data_type> myTree;

    // Functiions
    void CreateSegTree_(ptr_t start, ptr_t end, int node);

public:
    seg_tree(ptr_t first, ptr_t last, int size);
    friend ostream &operator<<(ostream &o, const seg_tree<ptr_t, functor> &s)
    {
        for (int i = 0; i <= s.size_; i++)
        {
            o << s.myTree[i] << "\t";
        }
        cout << "\n";

        return o;
    }

    data_type query(const ptr_t head, ptr_t start, ptr_t end, int L, int R, int node);
    // void update()
};

#endif
