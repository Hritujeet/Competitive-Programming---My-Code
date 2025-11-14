#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> q; // Max Heap

    q.push(3);
    q.push(4);
    cout << q.top() << endl;

    q.push(5);
    q.push(7);
    q.push(2);
    cout << q.top() << "\n";

    q.pop();
    cout << q.top() << "\n";

    q.pop();
    q.push(6);
    cout << q.top() << "\n";

    q.pop();
    cout << q.top() << endl;
    
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> q2; // Min Heap
    q2.push(3);
    q2.push(4);
    cout << q2.top() << endl;

    q2.push(5);
    q2.push(7);
    q2.push(2);
    cout << q2.top() << "\n";
    return 0;
}