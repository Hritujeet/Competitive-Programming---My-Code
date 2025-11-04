#include <iostream>
#include <algorithm>
using namespace std;

int binary_search(int* arr, int size, int element) {
    int st = 0, end = size-1;
    
    while (st <= end)
    {
        int mid = st + (end-st)/2;
        if (element < arr[mid])
        {
            end = mid-1;
        }

        else if (element > arr[mid]) {
            st = mid+1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int custom_search(int* arr, int n, int x) {
    auto a = lower_bound(arr, arr+n, x) - arr;
    if (a < n && arr[a] == x)
    {
        return a;
    }
    return -1;
}

int main(){
    int arr[] = {4,2,5,564,74,241,534,64};
    int size = (sizeof arr)/(sizeof arr[0]);

    sort(arr, arr+size);

    cout << binary_search(arr, size, 44) << endl;
    
    cout << binary_search(arr, size, 64) << endl;
    cout << custom_search(arr, size, 64) << endl;

    return 0;
}