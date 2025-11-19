#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_array(vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i];
    }
    cout << endl;
}

int first_occurance(vector<int> array, int size, int num)
{
    int st = 0;
    int end = size - 1;
    int mid, ans;

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
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}

int last_occurance(vector<int> array, int size, int num)
{
    int st = 0;
    int end = size - 1;
    int mid, ans;

    sort(array.begin(), array.end());

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
            ans = mid;
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> array = {1, 2, 2, 3, 5, 6, 22, 2, 2, 4, 5, 63, 3};
    int num;
    cin >> num;
    sort(array.begin(), array.end());

    print_array(array);
    cout << first_occurance(array, array.size(), num) << endl;
    cout << last_occurance(array, array.size(), num) << endl;

    return 0;
}