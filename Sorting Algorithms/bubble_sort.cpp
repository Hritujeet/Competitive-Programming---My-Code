#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

int main()
{
    int array[] = {1, 3, 8, 2, 9, 2, 5, 6};
    int size = (sizeof array) / (sizeof array[0]);

    print_array(size, array);
    bubble_sort(size, array);
    print_array(size, array);
    return 0;
}