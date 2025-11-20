#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> // We use priority_queue to maintain a min-heap of leaving times

using namespace std;
typedef long long ll;

/*
    Each customer has:
        a → ARRIVAL time
        b → LEAVING time

    We will treat each customer as an interval [a, b].
*/
struct Customer
{
    ll a; // Arrival time
    ll b; // Leaving time
};

/*
    Comparator for sorting customers:
        - First sort by arrival time (a)
        - If arrival times are equal, sort by leaving time (b)
    This ensures customers are processed in the exact order they arrive.
*/
bool compare(const Customer &x, const Customer &y)
{
    if (x.a != y.a)
        return x.a < y.a;
    return x.b < y.b;
}

/*
    Core idea (Sweep Line + Min-Heap):

    - After sorting by arrival time:
        When a new customer arrives:
            → first remove all customers who have ALREADY LEFT
            → then add this customer to the count

    - We use a MIN-HEAP (priority_queue with greater<ll>):
        Because the smallest leaving time must be checked first.
        This tells us which customer leaves next.

    - The heap size at any moment = number of customers currently in the restaurant.

    - The maximum heap size during the entire process is our answer.
*/
void solve(Customer *customers, ll n)
{
    // Step 1: Sort customers based on arrival time
    sort(customers, customers + n, compare);

    /*
        Min-Heap storing LEAVING TIMES of all customers currently inside.
        Why leaving times?
            → The one who leaves earliest must be popped first.
            → So we can efficiently remove all gone customers.
    */
    priority_queue<ll, vector<ll>, greater<ll>> leaving_times_min_heap;

    ll max_customers = 0; // Stores the maximum number of overlapping customers

    // Step 2: Process customers in arrival order
    for (ll i = 0; i < n; i++)
    {
        ll arrival_time = customers[i].a;
        ll leaving_time = customers[i].b;

        /*
            BEFORE adding this customer:

            Remove ALL customers whose leaving time is ≤ arrival_time.

            Explanation:
                If someone leaves at time = 5 and another arrives at time = 5,
                they DO NOT overlap → so remove them first.
        */
        while (!leaving_times_min_heap.empty() &&
               leaving_times_min_heap.top() <= arrival_time)
        {
            leaving_times_min_heap.pop();
        }

        // Step 3: Add this customer's leaving time to the heap
        leaving_times_min_heap.push(leaving_time);

        /*
            Step 4: Update the maximum active customers.
            The heap size shows how many customers are currently inside.
        */
        max_customers = max(max_customers, (ll)leaving_times_min_heap.size());
    }

    // Final answer
    cout << max_customers << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    // Dynamically allocate an array of customers
    Customer *customers = new Customer[n];

    // Read all customers (arrival, leaving)
    for (ll i = 0; i < n; i++)
    {
        cin >> customers[i].a >> customers[i].b;
    }

    // Compute maximum overlap
    solve(customers, n);

    // Free memory
    delete[] customers;

    return 0;
}
