#include <iostream>
#include <set>
#include <unordered_set> // Doesn't maintain order of elements

/*
multiset and unordered_multiset donot have the property of having unqie elements so they can have repetitions 

The methods of set, unorder_set, multiset, unordered_multiset are the same. They are almost the same with some fundamental differences
*/

/*
Operations:
1. Insertion (.insert)
2. Search (.count)
3. Removal (.erase)
*/

/*
Applications: 
1. Removing duplicates
2. Fast lookup actions because of linear time complexity for searching
3. Mathematical Set Operations
4. Graph Algorithms
*/

using namespace std;
typedef long long ll;

int main()
{
    set<ll> s;
    s.insert(3);
    s.insert(2);
    s.insert(5);
    s.insert(0);

    cout << s.count(3) << "\n"; // 1
    cout << s.count(4) << "\n"; // 0
    s.erase(3);
    s.insert(4);
    cout << s.count(3) << "\n"; // 0
    cout << s.count(4) << "\n"; // 1

    return 0;
}