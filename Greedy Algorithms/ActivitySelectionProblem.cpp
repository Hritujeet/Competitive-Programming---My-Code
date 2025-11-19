/*
***************Activity Selection Problem****************
Given n activites wiht starting time and ending time, choose maximum activities one can do without
any overlap of the timing since he or she can do only one activity at a time.

Greedy Approach = select the activity that has the least ending time so that we are left room to perform other activties.

1. Sort the activities by the ending in increasing order
2. Select the first activity
3. Choose other actvity such that the start time is greater than or equal to the end time of the previous activity
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct Activity
{
    int start;
    int end;
};

bool compareByEnd(const Activity &a, const Activity &b)
{
    return a.end < b.end;
}

void print_array(Activity *activities, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << activities[i].start << " " << activities[i].end << endl;
    }
}

void solve(Activity *activities, int size)
{
    int selections = 1;
    int current_end = activities[0].end;
    for (int i = 1; i < size; i++)
    {
        if (activities[i].start >= current_end)
        {
            selections++;
            current_end = activities[i].end;
        }
    }

    cout << selections << endl;
}

int main()
{
    Activity activities[6];
    int size = 6;

    activities[0].start = 0;
    activities[0].end = 6;

    activities[1].start = 3;
    activities[1].end = 4;

    activities[2].start = 1;
    activities[2].end = 2;

    activities[3].start = 5;
    activities[3].end = 9;

    activities[4].start = 5;
    activities[4].end = 7;

    activities[5].start = 8;
    activities[5].end = 9;

    sort(activities, activities + size, compareByEnd);
    print_array(activities, size);
    solve(activities, size);

    return 0;
}