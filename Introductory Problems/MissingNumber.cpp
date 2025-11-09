/*
You are given all numbers between 1,2,\ldots,n except one. Your task is to find the missing number.
Input
The first input line contains an integer n.
The second line contains n-1 numbers. Each number is distinct and between 1 and n (inclusive).
Output
Print the missing number.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll solve(vector<ll> numbers, ll n)
{
    sort(numbers.begin(), numbers.end());

    for (ll i = 1; i <= n; i++)
    {
        if (numbers[i - 1] != i)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> numbers;
    for (ll i = 0; i < n-1; i++)
    {
        ll inp;
        cin >> inp;
        numbers.push_back(inp);
    }

    cout << solve(numbers, n) << endl;

    return 0;
}