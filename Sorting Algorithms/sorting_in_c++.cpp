#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {4, 2, 5, 3, 5, 8, 3};
    sort(v.begin(), v.end());   // increasing order
    sort(v.rbegin(), v.rend()); // descreasing order

    int n = 7; // array size
    int a[] = {4, 2, 5, 3, 5, 8, 3};
    sort(a, a + n);

    string s = "monkey";
    sort(s.begin(), s.end());

    return 0;
}