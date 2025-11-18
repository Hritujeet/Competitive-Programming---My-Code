#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve(vector<ll>& coins, ll amount) {
	ll current_sum = 0;
	int no_of_coins = 0;
	int i = coins.size() - 1;

	while (i >= 0)
	{
		if (coins[i] > amount) {
			i--;
			continue;
		}
		else {
			if (coins[i] + current_sum < amount || coins[i] + current_sum == amount)
			{
				current_sum += coins[i];
				no_of_coins++;
			}
			else {
				i--;
			}
		}
		if (current_sum == amount)
		{
			cout << no_of_coins;
			break;
		}
	}
}

int main() {
	vector<ll> coins = { 1,2,5,10,20,50,100,200 };
	ll amount;
	cin >> amount;

	solve(coins, amount);
	return 0;
}