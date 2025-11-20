#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Utility function to print the array.
    Just prints elements in order without spaces (your original style).
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
    Finds the FIRST occurrence of 'num' in a sorted array.

    Logic:
        - Standard binary search framework.
        - When we find 'num', we don't stop.
        - Instead, we move LEFT (end = mid - 1) to check if there's an earlier one.
        - 'ans' stores the most recent match.

    Note:
        - array is passed by value → a copy. That's fine here,
          but pass-by-reference would be more efficient.
*/
int first_occurance(vector<int> array, int size, int num)
{
    int st = 0, end = size - 1;
    int mid;
    int ans = -1; // initialize with -1 so that “not found” is handled

    while (st <= end)
    {
        mid = st + ((end - st) / 2);

        if (array[mid] < num)
        {
            st = mid + 1; // go right
        }
        else if (array[mid] > num)
        {
            end = mid - 1; // go left
        }
        else
        {
            ans = mid;     // possible first occurrence found
            end = mid - 1; // keep searching left side
        }
    }
    return ans;
}

/*
    Finds the LAST occurrence of 'num' in a sorted array.

    Logic:
        - Same binary search style as first_occurrence.
        - When we find 'num', we store mid in ans.
        - But we move RIGHT (st = mid + 1) to find the last one.

    IMPORTANT NOTE:
        - The array is sorted AGAIN inside this function.
          That is unnecessary because main() already sorts it.
          Sorting inside is redundant → but kept since original code had it.
*/
int last_occurance(vector<int> array, int size, int num)
{
    int st = 0, end = size - 1;
    int mid;
    int ans = -1; // initialize with -1 for safety

    sort(array.begin(), array.end()); // redundant sort, but kept for explanation

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
            ans = mid;     // match found
            st = mid + 1;  // move RIGHT to find last one
        }
    }
    return ans;
}

int main()
{
    vector<int> array = {1, 2, 2, 3, 5, 6, 22, 2, 2, 4, 5, 63, 3};
    int num;

    cin >> num;

    // Array must be sorted for binary search
    sort(array.begin(), array.end());

    print_array(array);

    cout << first_occurance(array, array.size(), num) << endl;
    cout << last_occurance(array, array.size(), num) << endl;

    return 0;
}
