#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> // Required for priority_queue (Min-Heap)

using namespace std;
typedef long long ll;

struct Customer
{
    ll a; // Arrival time
    ll b; // Leaving time
};

// **CRITICAL CHANGE 1: Must sort by arrival time (a)**
bool compare(const Customer &x, const Customer &y)
{
    // If arrival times are the same, tie-break on earlier leaving time (optional but good practice)
    if (x.a != y.a) {
        return x.a < y.a;
    }
    return x.b < y.b; 
}

void solve(Customer *customers, ll n)
{
    // 1. Sort customers by arrival time
    sort(customers, customers + n, compare);
    
    // **CRITICAL CHANGE 2: Use a Min-Heap (Priority Queue)**
    // The heap stores the LEAVING TIMES (b) of all currently active customers.
    // We need the MINIMUM leaving time at the top to check who leaves earliest.
    priority_queue<ll, vector<ll>, greater<ll>> leaving_times_min_heap;
    
    ll max_customers = 0;

    // 2. Iterate through customers sorted by arrival
    for (ll i = 0; i < n; i++)
    {
        ll arrival_time = customers[i].a;
        ll leaving_time = customers[i].b;

        // **CRITICAL CHANGE 3: Use a WHILE loop to clear out ALL departed customers**
        // Remove customers whose leaving time is less than or equal to the current customer's arrival time.
        while (!leaving_times_min_heap.empty() && leaving_times_min_heap.top() <= arrival_time)
        {
            leaving_times_min_heap.pop();
        }

        // 3. Add the current customer's leaving time (they just arrived)
        leaving_times_min_heap.push(leaving_time);

        // 4. Update the maximum count
        // The heap size represents the current number of overlapping customers.
        max_customers = max(max_customers, (ll)leaving_times_min_heap.size());
    }

    cout << max_customers << endl;
}

int main()
{
    // Recommended competitive programming setup for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    if (!(cin >> n)) return 0;
    
    // Use a vector instead of a raw array for better C++ practice
    // (though using a raw array with `new` is fine for this context)
    Customer *customers = new Customer[n];

    for (ll i = 0; i < n; i++)
    {
        cin >> customers[i].a >> customers[i].b;
    }

    solve(customers, n);

    // Clean up memory
    delete[] customers; 

    return 0;
}