#include <iostream>
#include <vector>
using namespace std;

// Simple utility to swap two integers by pointer
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function: places pivot in its correct position
// and arranges smaller elements on its left, larger on its right.
int partition(vector<int> &arr, int st, int end)
{
    int idx = st - 1;         // boundary pointer for "smaller elements"
    int pivot = arr[end];     // choose last element as pivot

    // Scan the range [st, end-1]
    for (int j = st; j <= end - 1; j++)
    {
        // If element is smaller than pivot, expand the "smaller region"
        if (arr[j] < pivot)
        {
            idx++;                    // move boundary right
            swap(arr[j], arr[idx]);   // put smaller element into that position
        }
    }

    // Finally place pivot after the last smaller element
    idx++;
    swap(arr[end], arr[idx]);

    // idx is now the final position of the pivot
    return idx;
}

// QuickSort recursively sorts left and right subarrays around the pivot
void quicksort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        // Partition returns index where pivot belongs
        int pivot = partition(arr, st, end);

        // Sort the left side of pivot
        quicksort(arr, st, pivot - 1);

        // Sort the right side of pivot
        quicksort(arr, pivot + 1, end);
    }
}

int main()
{
    vector<int> arr = {12, 33, 35, 8, 32, 17, 35};

    // Call quicksort on the full array
    quicksort(arr, 0, arr.size() - 1);

    // Print sorted result
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
