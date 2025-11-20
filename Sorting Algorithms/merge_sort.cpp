#include <iostream>
#include <vector>
using namespace std;

/*
    ================================
    MERGE FUNCTION (Core Logic)
    ================================

    This function takes a portion of the array divided into two sorted halves:
        Left half   : st → mid
        Right half  : mid+1 → end

    Its job is to MERGE these two sorted halves into one sorted segment.
    This is the heart of merge sort.

    st  = starting index
    mid = middle index (end of left half)
    end = ending index
*/
void merge(vector<int> &array, int st, int mid, int end)
{
    vector<int> temp;     // temporary array to store sorted elements

    /*
        i → pointer for left half
        j → pointer for right half

        Left half  : [st ... mid]
        Right half : [mid+1 ... end]
    */
    int i = st;
    int j = mid + 1;

    /*
        Keep comparing top elements of both halves.
        Whichever is smaller, push it into temp.
        This works because both halves are ALREADY sorted.
    */
    while (i <= mid && j <= end)
    {
        if (array[i] < array[j])
        {
            temp.push_back(array[i]);
            i++;        // move left pointer
        }
        else
        {
            temp.push_back(array[j]);
            j++;        // move right pointer
        }
    }

    /*
        If the left half still has remaining elements,
        dump all of them into temp.
        (Right half is already empty here.)
    */
    while (i <= mid)
    {
        temp.push_back(array[i]);
        i++;
    }

    /*
        Same: if right half still has elements,
        push all of them into temp.
    */
    while (j <= end)
    {
        temp.push_back(array[j]);
        j++;
    }

    /*
        Now our temp array contains SORTED elements for the
        segment [st ... end]. Time to copy them back into
        the original array.

        NOTE:
        temp[0] → array[st]
        temp[1] → array[st+1]
        temp[2] → array[st+2]
        ...
    */
    for (int x = 0; x < temp.size(); x++)
    {
        array[st + x] = temp[x];
    }
}

/*
    ================================
    MERGE SORT FUNCTION (Recursion)
    ================================

    mergeSort works by:
    1. Splitting the array into two halves
    2. Sorting each half recursively
    3. Merging the two sorted halves

    st  = start index of current segment
    end = end index of current segment
*/
void mergeSort(vector<int> &array, int st, int end)
{
    // Base condition: stop when segment has 0 or 1 element
    if (st < end)
    {
        // Safe mid calculation to avoid overflow
        int mid = st + (end - st) / 2;

        // Sort left half: [st ... mid]
        mergeSort(array, st, mid);

        // Sort right half: [mid+1 ... end]
        mergeSort(array, mid + 1, end);

        // Merge the two sorted halves
        merge(array, st, mid, end);
    }
}

int main()
{
    vector<int> arr = {12, 35, 35, 8, 32, 17};

    // Call mergesort on the full array
    mergeSort(arr, 0, arr.size() - 1);

    // Print sorted array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
