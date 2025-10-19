/*
Time limit: 1.00 s
Memory limit: 512 MB

Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.
Input
The first input line has an integer n: the size of the array.
The second line has n integers x_1,x_2,\dots,x_n: the array values.
Output
Print one integer: the maximum subarray sum.
Constraints

1 \le n \le 2 \cdot 10^5
-10^9 \le x_i \le 10^9
*/
#include <iostream>
#include <climits>
using namespace std;

typedef long long ll;

ll maximum_subarray_sum(ll n, ll *array)
{
    ll best = LONG_MIN, current_sum = 0;
    for (ll i = 0; i < n; i++)
    {
        current_sum = max(array[i], current_sum + array[i]);
        best = max(best, current_sum);
    }
    return best;
}

int main()
{
    ll size;
    cin >> size;

    ll *arr = new ll[size];
    for (ll i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << maximum_subarray_sum(size, arr);
    delete[] arr;

    return 0;
}