/*
There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.
Input
The first input line contains integers n and m: the number of tickets and the number of customers.
The next line contains n integers h_1,h_2,\ldots,h_n: the price of each ticket.
The last line contains m integers t_1,t_2,\ldots,t_m: the maximum price for each customer in the order they arrive.
Output
Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.
If a customer cannot get any ticket, print -1.
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve(multiset<ll> &tickets, vector<ll> &customers)
{
    /*
    *************APROACH****************
    We maintain a sorted multiset of ticket prices and an unsorted arrya of customers. Then we iterate through the array of cutomers and find upper bound for each price declared by cutomers. If it points to begin then there exists no ticket for the user so we print -1. Otherwise we print the element just before the upperbound and erase it from the multiset
    */
    for (ll i = 0; i < customers.size(); i++)
    {
        auto it = tickets.upper_bound(customers[i]);

        if (it == tickets.begin()) {
            cout << -1 << endl;
        }
        else {
            it--;
            cout << *it << endl;
            tickets.erase(it);
        }
    }
    
}

int main()
{
    ll n, m;
    cin >> n >> m;

    multiset<ll> tickets;
    for (ll i = 0; i < n; i++)
    {
        ll inp;
        cin >> inp;
        tickets.insert(inp);
    }

    vector<ll> customers;
    for (ll i = 0; i < m; i++)
    {
        ll inp;
        cin >> inp;
        customers.push_back(inp);
    }

    solve(tickets, customers);

    return 0;
}