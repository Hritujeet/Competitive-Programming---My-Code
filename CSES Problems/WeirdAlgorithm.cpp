/*
    This is the classic "Weird Algorithm" (also known as the Collatz sequence).

    RULES:
        - Start with a number n.
        - If n is EVEN → replace n with n / 2
        - If n is ODD  → replace n with 3*n + 1
        - Repeat until n becomes 1.

    Example for n = 3:
        3 → 10 → 5 → 16 → 8 → 4 → 2 → 1

    The task is to PRINT the entire sequence from start to end.
*/

#include <iostream>
using namespace std;
typedef long long ll;

/*
    This function prints the Collatz sequence using RECURSION.

    LOGIC:
        - Print the current n
        - If n becomes 1 → stop (base case)
        - Otherwise apply the rule:
            EVEN → n = n / 2
            ODD  → n = 3*n + 1
        - Then recursively call the function for the new n

    Note:
        Recursion works here because max depth is manageable,
        but for extremely large n an iterative solution is safer.
*/
void weird_algorithm(ll n)
{
    cout << n << " ";  // Always print current value immediately

    if (n == 1)
    {
        return;        // Base case: sequence ends at 1
    }

    /*
        If n is even:
            - Just divide by 2
        Example:
            n = 16 → next = 8
    */
    if (n % 2 == 0)
    {
        weird_algorithm(n / 2);
    }
    /*
        If n is odd:
            - Apply the formula 3*n + 1
        Example:
            n = 5 → next = 16
    */
    else
    {
        weird_algorithm(3 * n + 1);
    }
}

int main()
{
    ll n;
    cin >> n;   // Read the starting number

    weird_algorithm(n);  // Trigger the recursive simulation

    return 0;
}
