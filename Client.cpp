#include <iostream>
using namespace std;
#include <vector>
#include "./src/segTree.h"


int main(int argc, char const *argv[])
{
    vector<int> v = {1, 1, 1, 1, 1};

    vector<int>::iterator it;

    seg_tree<vector<int>::iterator, Add<int>> s(begin(v), end(v) - 1, v.size());

    cout << s << "\n";

    s.update(begin(v), begin(v), end(v) - 1, 1, 2, 0, 6, addEq<int>());
    s.update(begin(v), begin(v), end(v) - 1, 3, 4, 0, 4, Eq<int>());

    cout << s << "\n";

    auto val = s.query(v.begin(), v.begin(), end(v) - 1, 1, 4, 0);
    cout << val << " ---\n";

    return 0;
}
