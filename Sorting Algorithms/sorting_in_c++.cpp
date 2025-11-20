#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // A vector with some unsorted integers
    vector<int> v = {4, 2, 5, 3, 5, 8, 3};

    // Sorts the vector in *increasing* order (smallest → largest)
    sort(v.begin(), v.end());

    // Sorts the vector in *decreasing* order (largest → smallest)
    // rbegin() and rend() give reverse iterators, which flips the order
    sort(v.rbegin(), v.rend());

    // A normal C-style array
    int n = 7;
    int a[] = {4, 2, 5, 3, 5, 8, 3};

    // Sorting a raw array (increasing order)
    // 'a' is the starting pointer, 'a + n' is the end pointer
    sort(a, a + n);

    // Sorting a string
    // Works because string is basically a char array
    string s = "monkey";

    // Characters get sorted by ASCII value ('e' < 'k' < 'm' < 'n' ...)
    sort(s.begin(), s.end());

    return 0;
}
