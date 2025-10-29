#include <iostream>
using namespace std;
typedef long long ll;

void print_array(ll n, ll *array)
{
    for (ll i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void merge_procedure(ll a[], ll b[], ll m, ll n)
{
    ll i = 0, j = 0, k = 0;
    ll *newArray = new ll[m + n];

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            newArray[k] = a[i];
            i++;
            k++;
        }
        else
        {
            newArray[k] = b[j];
            j++;
            k++;
        }
    }

    while (i < m)
    {
        newArray[k] = a[i];
        i++;
        k++;
    }

    while (j < n)
    {
        newArray[k] = b[j];
        j++;
        k++;
    }

    print_array(m + n, newArray);
}

int main()
{
    ll a[] = {7, 9, 18, 19, 22};
    ll m = (sizeof a) / (sizeof a[0]);

    ll b[] = {1, 6, 9, 11};
    ll n = (sizeof b) / (sizeof b[0]);

    merge_procedure(a, b, m, n);
    return 0;
}