#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5, 6};

    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (vector<int>::reverse_iterator i = numbers.rbegin(); i != numbers.rend(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}