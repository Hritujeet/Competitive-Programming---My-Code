/*
    Problem: Ferris Wheel (CSES Problem Set)
    Objective:
        - You must assign children to gondolas.
        - Each gondola can carry EITHER:
              * one child, OR
              * two children
        - The total weight of the children inside a gondola cannot exceed x.
    Output:
        - The MINIMUM number of gondolas required.

    Key Insight (Greedy Two-Pointer Strategy):
        - To minimize gondolas, we try to PAIR the lightest child with the heaviest child whenever possible.
        - If the lightest + heaviest ≤ x → pair them (best possible saving).
        - Otherwise → the heaviest child must ride alone.
        - Sorting + pairing from ends gives an optimal solution.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

/*
    Computes the minimum number of gondolas needed.

    Approach Breakdown:
        1. Sort the array of weights.
           This ensures we always consider the smallest and largest available child.

        2. Use two pointers:
               i → points to lightest remaining child.
               j → points to heaviest remaining child.

        3. While i ≤ j:
               Case A: children[i] + children[j] ≤ x
                       → They can share a gondola.
                       → Move i forward (light child used).
                       → Move j backward (heavy child used).
                       → One gondola used.

               Case B: children[i] + children[j] > x
                       → Heaviest child must go alone.
                       → Move j backward only.
                       → One gondola used.

        4. Continue until all children are assigned.

    This greedy pairing minimizes total gondolas.
*/
int min_no_of_gondolas(vector<ll> &children, ll n, ll x) {
    sort(children.begin(), children.end());  // Step 1: sort the weights

    ll i = 0;        // pointer to the lightest child
    ll j = n - 1;    // pointer to the heaviest child
    ll gondolas = 0; // total gondolas used

    // Step 2 & 3: two-pointer pairing loop
    while (i <= j) {
        
        // If pairing is possible → pair lightest + heaviest
        if (children[i] + children[j] <= x) {
            i++;  
        }
        // Whether paired or alone, the heaviest child (j) always sits now
        j--;       
        
        gondolas++;  // One gondola used for this iteration
    }

    return gondolas;
}

int main()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> children(n);

    // Input all children's weights
    for (int i = 0; i < n; i++)
    {
        cin >> children[i];
    }

    // Compute and print minimum gondolas
    cout << min_no_of_gondolas(children, n, x);

    return 0;
}
