/*
You are given all numbers between 1,2,...,n except one.
Your task is to find the missing number.

Input:
- First line: integer n
- Second line: n-1 distinct integers between 1 and n

Output:
- Print the missing number.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll solve(vector<ll> &numbers, ll n)
{
    // Step 1: Sort the given numbers so that they become 1,2,3,... except one missing.
    // After sorting, the correct number for index i-1 should be i.
    sort(numbers.begin(), numbers.end());

    /*
        Step 2: Scan from 1 to n-1
        For each expected number i:
        - numbers[i-1] is what actually appears in the array at that position.
        - If numbers[i-1] != i → this means i is missing.

        Example:
            n = 5
            numbers = {1, 2, 4, 5}
            sorted = {1, 2, 4, 5}
            i = 1 → numbers[0] = 1 ✔️
            i = 2 → numbers[1] = 2 ✔️
            i = 3 → numbers[2] = 4 ❌ mismatch → 3 is missing
    */
    for (ll i = 1; i <= n - 1; i++)
    {
        if (numbers[i - 1] != i)
        {
            return i; // immediately return the missing number
        }
    }

    /*
        Step 3: If the loop did not return anything,
                it means that numbers = {1, 2, ..., n-1}
                So the missing number must be n.
    */
    return n;
}

int main()
{
    ll n;
    cin >> n;

    // We expect n-1 numbers, so reserve space for efficiency.
    vector<ll> numbers;
    numbers.reserve(n - 1);

    // Read the n-1 distinct integers
    for (ll i = 0; i < n - 1; i++)
    {
        ll inp;
        cin >> inp;
        numbers.push_back(inp);
    }

    // Output the missing number
    cout << solve(numbers, n) << endl;

    return 0;
}
