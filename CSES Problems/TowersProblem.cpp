#include <iostream>
#include <vector>
#include <set>

// Use the standard namespace for easier access to common functions
using namespace std;
// Define a type alias for long long to simplify code and ensure large cube sizes are handled
typedef long long ll; 

/**
 * @brief Solves the Towers problem using a greedy approach with a multiset.
 * * The minimum number of towers is found by always placing the current cube 
 * on the existing tower whose top cube is the smallest one that is still 
 * strictly larger than the current cube.
 *
 * @param cubes A vector containing the sizes of the cubes in the order they arrive.
 * @param n The total number of cubes.
 */
void solve(vector<ll> cubes, ll n)
{
    // The multiset stores the size of the *TOP CUBE* of every existing tower.
    // The multiset automatically keeps these top cube sizes sorted, which
    // is essential for the O(log N) search using upper_bound.
    multiset<ll> towers;
    
    // Optimization/Minor detail: The first cube always starts a new tower.
    if (n > 0) {
        towers.insert(cubes[0]);
    }

    // Process the remaining cubes one by one, starting from the second cube (index 1).
    for (ll i = 1; i < n; i++)
    {
        // Get an iterator to the first element in 'towers' that is 
        // STRICTLY GREATER than the current cube size (cubes[i]).
        // This is the *greedy choice* because it represents the smallest top cube 
        // that is still large enough to accept cubes[i] on top of it.
        auto top = towers.upper_bound(cubes[i]);
        
        // Case 1: No suitable tower was found.
        // 'upper_bound' returned the end iterator, meaning all existing top cubes 
        // are less than or equal to cubes[i]. Since the new cube must be smaller 
        // than the cube below it, we must start a NEW tower.
        if (top == towers.end())
        {
            towers.insert(cubes[i]);
        }
        // Case 2: A suitable tower was found.
        // 'top' points to the smallest top cube T such that T > cubes[i].
        else
        {
            // First, remove the old top cube size (*top) from the multiset.
            // This tower now has a new top cube.
            towers.erase(top);
            
            // Second, insert the new top cube size (cubes[i]) into the multiset.
            // The size of the multiset (number of towers) remains unchanged.
            towers.insert(cubes[i]);
        }
    }
    
    // The final size of the multiset is the minimum possible number of towers.
    cout << towers.size() << endl;
}

/**
 * @brief Main function for reading input and calling the solver.
 */
int main()
{
    // Optimization: Unties C++ standard I/O streams from C standard I/O streams 
    // and turns off synchronization, speeding up input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    // Read the number of cubes.
    cin >> n;

    // Declare a vector of size n to store the cube sizes.
    vector<ll> cubes(n);
    
    // Loop n times to read all cube sizes into the vector.
    for (ll i = 0; i < n; i++)
    {
        // Correctly read the i-th cube size into the i-th element of the vector.
        cin >> cubes[i]; 
    }

    // Call the solve function with the cube data.
    solve(cubes, n);

    return 0;
}