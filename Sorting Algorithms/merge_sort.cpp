#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &array, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (array[i] < array[j])
        {
            temp.push_back(array[i]);
            i++;
        }

        else
        {
            temp.push_back(array[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(array[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(array[j]);
        j++;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        array[i + st] = temp[i];
    }
}

void mergeSort(vector<int> &array, int st, int end)
{
    if (st < end)
    {
        int mid = st + ((end - st) / 2);

        mergeSort(array, st, mid);
        mergeSort(array, mid + 1, end);

        merge(array, st, mid, end);
    }
}

int main()
{
    vector<int> arr = {12, 35, 35, 8, 32, 17};

    mergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}