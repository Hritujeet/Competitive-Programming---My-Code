#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    map<string, ll> marks;

    marks["Hritujeet Sharma"] = 98;
    marks["Amitabh Bachchan"] = 75;
    marks["Carryminati"] = 43;

    if (marks.count("Hritujeet"))
    {
        cout << "Oh Yeah" << endl;
    }

    else
    {
        cout << "hehehehe" << endl;
    }

    for (auto x: marks) {
        cout << x.first << " has scored " << x.second << endl;
    }

    return 0;
}