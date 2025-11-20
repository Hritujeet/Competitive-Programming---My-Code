/*
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.
What is the minimum number of gondolas needed for the children?
Input
The first input line contains two integers n and x: the number of children and the maximum allowed weight.
The next line contains n integers p_1,p_2,\ldots,p_n: the weight of each child.
Output
Print one integer: the minimum number of gondolas.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int min_no_of_gondolas(vector<ll> &children, ll n, ll x) {
    sort(children.begin(), children.end());

    ll i = 0, j = n - 1;
    ll gondolas = 0;

    while (i <= j) {
        if (children[i] + children[j] <= x) {
            i++;     // Pair the heavier with the lighter
        }
        j--; // The heavier will always sit
        gondolas++;
    }

    return gondolas;
}


int main()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> children(n);
    for (int i = 0; i < n; i++)
    {
        cin >> children[i];
    }

    cout << min_no_of_gondolas(children, n, x);

    return 0;
}