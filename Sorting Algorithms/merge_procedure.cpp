#include <iostream>
using namespace std;
typedef long long ll;

void print_array(ll n, ll *array)
{
    for (ll i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void merge_procedure(ll a[], ll b[], ll m, ll n)
{
    // i  -> pointer for array a
    // j  -> pointer for array b
    // k  -> pointer for the new merged array
    ll i = 0, j = 0, k = 0;

    // Create a new array of size (m + n)
    // This will store the final merged sorted array
    ll *newArray = new ll[m + n];

    /*
        STEP 1:
        Merge elements while BOTH arrays still have elements left.

        Since both 'a' and 'b' are already sorted,
        we simply compare the current elements:

        - If a[i] < b[j] -> a[i] goes into newArray
        - Else -> b[j] goes into newArray

        This is the heart of the merge step used in merge sort.
    */
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            newArray[k] = a[i];
            i++;    // move pointer in array a
            k++;    // move pointer in merged array
        }
        else
        {
            newArray[k] = b[j];
            j++;    // move pointer in array b
            k++;    // move pointer in merged array
        }
    }

    /*
        STEP 2:
        If ANY elements are left in array a, copy them.
        (This happens when array b finishes first.)
    */
    while (i < m)
    {
        newArray[k] = a[i];
        i++;
        k++;
    }

    /*
        STEP 3:
        If ANY elements are left in array b, copy them.
        (This happens when array a finishes first.)
    */
    while (j < n)
    {
        newArray[k] = b[j];
        j++;
        k++;
    }

    // Print the merged sorted array
    print_array(m + n, newArray);

    // Free dynamically allocated memory
    delete newArray;
}

int main()
{
    // First sorted array
    ll a[] = {7, 9, 18, 19, 22};
    ll m = (sizeof a) / (sizeof a[0]);

    // Second sorted array
    ll b[] = {1, 6, 9, 11};
    ll n = (sizeof b) / (sizeof b[0]);

    // Merge the two arrays
    merge_procedure(a, b, m, n);
    return 0;
}
