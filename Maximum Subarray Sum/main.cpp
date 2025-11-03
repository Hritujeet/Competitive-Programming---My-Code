#include <iostream>
#include <climits>
using namespace std;

void print_subarrays(int n, int *array)
{
    /*
    1. Pickup a starting index of any type of subarray. Multiple subarrays can have same starting point.
    2. Pickup and match Ending index and constant starting index combinations to produce all possible subarrays
    3. Iterate over the subarray with a given starting index and ending index

    total subarrays = [n(n+1)]/2
    */

    // The starting index of the subarray
    for (int i = 0; i < n; i++)
    {
        // The ending index of the subarray
        for (int j = i; j < n; j++)
        {
            cout << "["; // Start of the subarray

            // Loop to print the elements from the start index (i) to the end index (j)
            for (int k = i; k <= j; k++) // Use k <= j to include the element at index j
            {
                cout << array[k]; // Print the VALUE at index k

                // Print a comma and space unless it's the last element of the subarray
                if (k < j)
                {
                    cout << ", ";
                }
            }

            cout << "]";  // End of the subarray
            cout << endl; // FIX 3: Print a newline after *each* subarray
        }
    }
}

int brute_force_solution(int n, int *array)
{
    int best_sum = 0;

    // Picking up a starting index for a subarray
    for (int i = 0; i < n; i++)
    {
        // Creating combinations of multiple ending indices with the starting index to create a subarray
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            // Iterate over the subarray and add the values to get sum and max sum
            for (int k = i; k <= j; k++)
            {
                sum += array[k];
            }
            best_sum = max(best_sum, sum);
        }
    }

    return best_sum;
}

int optimized_brute_force(int n, int *array)
{
    int best_sum = 0;
    // Picking up a starting index for a subarray
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        // Creating combinations of multiple ending indices with the starting index to create a subarray
        for (int j = i; j < n; j++)
        {
            // As we move to the right in subarrays with a given starting index, the sum increase y the value of last element. So we keep on addiing and updating without ietarting over the obtained subarray
            sum += array[j];
            best_sum = max(best_sum, sum);
        }
    }
    return best_sum;
}

int kadane_alogorithm(int n, int *array)
{
    // Initailize best_sum which is result and current_sum which keeps track of current sum to caluclate best sum
    int best_sum = INT_MIN, current_sum = 0;
    for (int i = 0; i < n; i++)
    {
        // We update current sum as maximum of the element at index i and the sum of the current sum till now with element at index i. Our value rests evrytime we obtain a smaller sum
        current_sum = max(array[i], current_sum + array[i]);

        // We update best sum as best sum till now and current sum calculated above to keep track of best sum which we may encounter.
        best_sum = max(best_sum, current_sum);
    }
    return best_sum;
}

int main()
{
    int array[8] = {-1, 2, 4, -3, 5, 2, -5, 2};
    int size = (sizeof array) / (sizeof array[0]);

    cout << "All the subarrays of the array ar as follows:" << endl;
    print_subarrays(size, array);
    cout << endl;

    cout << brute_force_solution(size, array) << endl;
    cout << optimized_brute_force(size, array) << endl;
    cout << kadane_alogorithm(size, array) << endl;
    return 0;
}