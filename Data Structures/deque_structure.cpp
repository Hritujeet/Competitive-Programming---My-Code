#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> d = {1,2,3,4,5};

    d.push_back(6);
    d.push_front(0);

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << endl;
    }

    cout << endl;

    d.pop_front();
    d.pop_back();

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << endl;
    }
    
    return 0;
}