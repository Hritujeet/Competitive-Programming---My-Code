#include <iostream>
using namespace std;

int first_occurrance(int *arr, int n, int x)
{
    int st = 0;
    int end = n - 1;
    int mid;
    int ans = -1;

    while (st <= end)
    {
        mid = st + ((end - st) / 2);

        if (arr[mid] > x)
        {
            end = mid - 1;
        }

        else if (arr[mid] < x)
        {
            st = mid + 1;
        }

        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}

int last_occurrance(int *arr, int n, int x)
{
    int st = 0;
    int end = n - 1;
    int mid;
    int ans = -1;

    while (st <= end)
    {
        mid = st + ((end - st) / 2);

        if (arr[mid] > x)
        {
            end = mid - 1;
        }

        else if (arr[mid] < x)
        {
            st = mid + 1;
        }

        else
        {
            ans = mid;
            st = mid + 1;
        }
    }
    return ans;
}

int count_occurrances(int *arr, int size, int x)
{
    int first = first_occurrance(arr, size, x);
    if (first == -1)
    {
        return 0;
    }
    int last = last_occurrance(arr, size, x);
    return (last - first) + 1;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 3, 4, 6, 6, 6, 6, 7};
    int size = (sizeof arr) / (sizeof arr[0]);

    cout << count_occurrances(arr, size, 2) << endl;
    cout << count_occurrances(arr, size, 1) << endl;
    cout << count_occurrances(arr, size, 6) << endl;

    return 0;
}