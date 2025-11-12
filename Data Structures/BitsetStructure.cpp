#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    bitset<5> b1;
    b1[1] = 1;

    for (int i = 0; i < b1.size(); i++)
    {
        cout << b1[i] << endl;
    }

    cout << endl;

    bitset<5> b2(string("01011"));
    for (int i = 0; i < b2.size(); i++)
    {
        cout << b2[i] << endl;
    }

    bitset<10> a(string("0010110110"));
    bitset<10> b(string("1011011000"));
    cout << (a & b) << "\n"; // 0010010000 -> both true
    cout << (a | b) << "\n"; // 1011111110 -> at least one true
    cout << (a ^ b) << "\n"; // 1001101110 -> only one true
    return 0;
}