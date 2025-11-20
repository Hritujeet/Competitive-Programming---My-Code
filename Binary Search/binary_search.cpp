#include <iostream>
#include <algorithm>
using namespace std;

/*
    This is a manual implementation of binary search.
    It assumes that 'arr' is already sorted in increasing order.

    Parameters:
        arr   -> pointer to the sorted array
        size  -> number of elements in the array
        element -> the value we want to search for

    Returns:
        index of 'element' if found
        -1 if the element does not exist in the array
*/
int binary_search(int* arr, int size, int element) {
    int st = 0, end = size - 1;

    // Binary search runs while the search space is valid
    while (st <= end) {

        // mid is chosen this way to avoid integer overflow
        int mid = st + (end - st) / 2;

        // If the element is smaller, it must be in the left half
        if (element < arr[mid]) {
            end = mid - 1;
        }

        // If the element is larger, move to the right half
        else if (element > arr[mid]) {
            st = mid + 1;
        }

        // Exact match found
        else {
            return mid;
        }
    }

    // If loop ends, element was not found
    return -1;
}

/*
    This uses C++ STL lower_bound().
    lower_bound(arr, arr+n, x) gives the FIRST index
    where x could be inserted without violating the sorted order.

    Steps:
        - lower_bound gives a pointer to the first element >= x
        - We subtract arr to convert pointer to index
        - If that index exists and arr[index] == x, then x is present

    Returns:
        index of x if exists
        -1 otherwise
*/
int custom_search(int* arr, int n, int x) {
    auto a = lower_bound(arr, arr + n, x) - arr;  // convert pointer → index

    // Check if x actually exists at that index
    if (a < n && arr[a] == x) {
        return a;
    }

    return -1;
}

int main() {
    int arr[] = {4, 2, 5, 564, 74, 241, 534, 64};
    int size = sizeof(arr) / sizeof(arr[0]);  // number of elements

    sort(arr, arr + size);  // binary search requires sorted array

    // Searching for 44 (not present)
    cout << binary_search(arr, size, 44) << endl;

    // Searching for 64 (present)
    cout << binary_search(arr, size, 64) << endl;
    cout << custom_search(arr, size, 64) << endl;

    return 0;
}
