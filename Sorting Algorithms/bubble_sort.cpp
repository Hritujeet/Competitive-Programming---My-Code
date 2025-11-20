#include <iostream>
using namespace std;

// Simple swap function that swaps the VALUES of two integers
void swap(int *a, int *b)
{
    int temp = *a;  // store value of a temporarily
    *a = *b;        // put b's value into a
    *b = temp;      // put stored value (old a) into b
}

// Utility function to print the array
void print_array(int n, int *array)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int n, int *array)
{
    /*
        Bubble Sort Logic:
        ------------------
        - We repeatedly compare adjacent pairs.
        - If the left element is greater than the right element,
          we swap them (so larger values "bubble" to the end).
        - After every full pass, the largest element moves
          to its correct position at the right side.

        Time complexity: O(n^2)
    */

    // Outer loop → number of passes needed
    for (int i = 0; i < n; i++)
    {
        // Inner loop → compares each adjacent pair
        for (int j = 0; j < n - 1; j++)
        {
            // If left value > right value → swap them
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
        // After each pass, the largest element among the unsorted part
        // is placed at the end. Bubble sort is slow but simple.
    }
}

int main()
{
    // Sample unsorted array
    int array[] = {1, 3, 8, 2, 9, 2, 5, 6};
    int size = (sizeof array) / (sizeof array[0]);

    print_array(size, array);    // Print before sorting
    bubble_sort(size, array);    // Sort the array
    print_array(size, array);    // Print after sorting

    return 0;
}
