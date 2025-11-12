#include <iostream>
#include <set>

using namespace std;

void find_nearest(set<int> s, int x)
{
    set<int>::iterator it = s.lower_bound(x);

    if (it == s.begin())
    {
        cout << *it << endl;
    }

    else if (it == s.end())
    {
        it--;
        cout << *it << endl;
    }
    else
    {
        auto next = *it;
        it--;
        auto preceding = *it;

        if (x - preceding > next - x)
        {
            cout << next << endl;
        }
        else
        {
            cout << preceding << endl;
        }
    }
}

int main()
{
    set<int> mySet;
    mySet.insert(10);
    mySet.insert(92);
    mySet.insert(33);
    mySet.insert(7);

    int x = 55;

    set<int>::iterator setIterator = mySet.begin();
    for (auto i = mySet.begin(); i != mySet.end(); i++)
    {
        cout << *i << endl;
    }

    find_nearest(mySet, x);

    return 0;
}