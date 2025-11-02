#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int> &arr, int st, int end)
{
    int idx = st - 1, pivot = arr[end];

    for (int j = st; j <= end - 1; j++)
    {
        if (arr[j] < pivot)
        {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quicksort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int pivot = partition(arr, st, end);

        quicksort(arr, st, pivot - 1);
        quicksort(arr, pivot + 1, end);
    }
}

int main()
{
    vector<int> arr = {12, 33, 35, 8, 32, 17, 35};
    quicksort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}