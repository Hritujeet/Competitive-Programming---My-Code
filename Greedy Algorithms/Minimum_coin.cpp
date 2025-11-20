#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

/*
    Greedy Coin Selection
    ---------------------
    We are given a fixed set of coin denominations (like in real currency).
    The goal is to make a given amount using the *minimum number of coins*.

    Greedy Idea:
        Always pick the largest coin that does NOT exceed the remaining amount.
        This works because larger coins reduce the remaining amount faster,
        and this specific coin system (1,2,5,10,20,50,100,200) is "canonical",
        meaning greedy always gives the optimal answer.

    Approach:
        - Start from the largest coin.
        - Keep picking it while it fits in the remaining amount.
        - Move to the next coin only when the current one is too big.
        - Count how many coins are used.
*/

void solve(vector<ll>& coins, ll amount) {
    ll current_sum = 0;   // How much amount we have formed so far
    int no_of_coins = 0;  // How many coins we have picked
    int i = coins.size() - 1;  // Start from the largest coin

    // Loop until we run out of coin types
    while (i >= 0)
    {
        // If this coin is larger than the target amount,
        // we simply skip it because it can never be used.
        if (coins[i] > amount) {
            i--;
            continue;
        }

        /*
            If adding this coin does NOT exceed the target amount,
            then it's safe to take it.

            Example:
                amount = 27
                current_sum = 12
                trying coin 10:
                    12 + 10 = 22  (<= 27) → okay, take it
        */
        if (current_sum + coins[i] <= amount)
        {
            current_sum += coins[i];  // Add the coin to our sum
            no_of_coins++;            // Count the coin
        }
        else {
            // If the coin makes us cross the target,
            // try the next smaller coin.
            i--;
        }

        // If we have exactly reached the amount, we are done.
        if (current_sum == amount)
        {
            cout << no_of_coins;
            break;
        }
    }
}

int main() {
    // The given coin system (like Indian/Euro denominations)
    vector<ll> coins = { 1,2,5,10,20,50,100,200 };

    ll amount;
    cin >> amount;  // Read the target amount

    solve(coins, amount);
    return 0;
}
