/*
You are given a list of n integers, and your task is to calculate the number of distinct values in the list.
Input
The first input line has an integer n: the number of values.
The second line has n integers x_1,x_2,\dots,x_n.
Output
Print one integers: the number of distinct values.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
void solve(vector<ll> &numbers, ll n)
{
    sort(numbers.begin(), numbers.end());
    ll distinct = 1;

    for (ll i = 1; i < n; i++)
    {
        if (numbers[i] != numbers[i - 1])
        {
            distinct++;
        }
    }
    cout << distinct;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> numbers;
    for (ll i = 0; i < n; i++)
    {
        ll inp;
        cin >> inp;
        numbers.push_back(inp);
    }

    solve(numbers, n);

    return 0;
}