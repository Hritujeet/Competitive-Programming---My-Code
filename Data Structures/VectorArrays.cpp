#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    vector<ll> numbers;

    numbers.push_back(5);
    numbers.push_back(66);
    numbers.push_back(67);
    numbers.push_back(1);

    cout << numbers[0] << endl;
    cout << numbers.size() << endl;

    for (ll i = 0; i < numbers.size(); i++)
    {
        cout << numbers.at(i) << " ";
    }
    cout << endl;

    cout << numbers.back() << endl;
    cout << numbers.front() << endl;
    

    return 0;
}