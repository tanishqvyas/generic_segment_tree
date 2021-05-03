#include <iostream>
#include <vector>
#include "./src/segTree.h"

using namespace std;


int main(int argc, char const *argv[])
{
    vector<int> v = {1, 1, 1, 1, 1};

    vector<int>::iterator it;

  	// Create a Segment Tree for Range Sum query
    seg_tree<vector<int>::iterator, Add<int>> s(begin(v), end(v) - 1, v.size());

	// Display created Segment Tree
    cout << s << "\n";

    // Constant
    int const_val1 = 6;
    int const_val2 = 4;

    // Update Query for increasing all values by 6
    s.update(begin(v), begin(v), end(v) - 1, 1, 2, 0, const_val1, addEq<int>());

    // Update query to set all values in the range as 4
    s.update(begin(v), begin(v), end(v) - 1, 3, 4, 0, const_val2, Eq<int>());

    cout << s << "\n";

    // Performing Range Sum Query
    auto val = s.query(v.begin(), v.begin(), end(v) - 1, 1, 4, 0);
    cout << val << "\n";

    return 0;
}
