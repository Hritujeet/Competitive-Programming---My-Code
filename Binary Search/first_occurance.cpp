/*
Problem: Find First and Last Occurrence of a Number in a Sorted Array
Objective:
    Given a sorted list of integers, determine:
        1. The first (leftmost) index where a given number appears.
        2. The last (rightmost) index where the same number appears.

Why Sorting?
    Binary search works ONLY on sorted arrays. We sort the array once in main().
    The search functions then assume the input is already sorted.

Technique Used:
    Modified Binary Search.
    Instead of stopping when we find the target, we keep searching:
        - For first occurrence → push the search LEFT.
        - For last occurrence → push the search RIGHT.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Utility function to print the array.
This simply prints all elements in one line without spaces.
*/
void print_array(vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i];
    }
    cout << endl;
}

/*
Function: first_occurance
Goal:
    Find the FIRST (leftmost) index where 'num' appears.

Key Idea:
    Standard binary search, but when we find the target:
        - We store the index (ans = mid)
        - Then search the LEFT half (end = mid - 1)
      because a smaller index may still contain the same number.

Notes:
    - 'ans' must be initialized to -1 to indicate "not found".
*/
int first_occurance(vector<int> array, int size, int num)
{
    int st = 0;
    int end = size - 1;
    int mid;
    int ans = -1; // initialize properly

    while (st <= end)
    {
        mid = st + ((end - st) / 2);

        if (array[mid] < num)
        {
            // Current element is smaller → move RIGHT
            st = mid + 1;
        }
        else if (array[mid] > num)
        {
            // Current element is bigger → move LEFT
            end = mid - 1;
        }
        else
        {
            // Match found → record it
            ans = mid;

            // But there might be an earlier one → search LEFT side
            end = mid - 1;
        }
    }
    return ans;
}

/*
Function: last_occurance
Goal:
    Find the LAST (rightmost) index where 'num' appears.

Key Difference from first_occurance:
    After finding a match:
        - We record the index (ans = mid)
        - But then move RIGHT (st = mid + 1)
      because a later index may still contain the same number.

Important:
    This function unnecessarily sorts the array again.
    The main() already sorts it, so this line:
        sort(array.begin(), array.end());
    is redundant. Kept only to reflect the original code structure.
*/
int last_occurance(vector<int> array, int size, int num)
{
    int st = 0;
    int end = size - 1;
    int mid;
    int ans = -1; // initialize properly

    sort(array.begin(), array.end()); // redundant but unchanged

    while (st <= end)
    {
        mid = st + ((end - st) / 2);

        if (array[mid] < num)
        {
            st = mid + 1;
        }
        else if (array[mid] > num)
        {
            end = mid - 1;
        }
        else
        {
            // Match found
            ans = mid;

            // Look for a later match → go RIGHT
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    // Initial unsorted array with repeated values
    vector<int> array = {1, 2, 2, 3, 5, 6, 22, 2, 2, 4, 5, 63, 3};

    int num;
    cin >> num; // number to search for

    // Sorting is required before performing binary searches
    sort(array.begin(), array.end());

    print_array(array); // visualize sorted array

    // Print first and last occurrences
    cout << first_occurance(array, array.size(), num) << endl;
    cout << last_occurance(array, array.size(), num) << endl;

    return 0;
}
