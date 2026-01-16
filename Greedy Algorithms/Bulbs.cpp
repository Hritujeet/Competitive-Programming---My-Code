#include <iostream>
using namespace std;

int flip_switches(int *bulbs, int n)
{
    int cost = 0;

    for (int i = 0; i < n; i++)
    {
        if (cost % 2 == 0)
        {
            // The cost is even so the current state of the bulb is its true state and doesnt need to be flipped
            bulbs[i] = bulbs[i];
        }
        else
        {
            // The cost is odd co the current state of the bubl is not its true state and has to be flipped
            bulbs[i] = !bulbs[i];
        }

        if (bulbs[i] == 1)
        {
            continue;
        }
        else
        {
            cost++;
        }
    }
    return cost;
}

int main()
{
    int bulbs[] = {0, 1, 0, 1, 1, 0, 0, 1, 1, 0};
    int size = (sizeof bulbs) / (sizeof bulbs[0]);

    cout << "The answer is " << flip_switches(bulbs, size) << endl;
    return 0;
}