/*
******************** Activity Selection Problem ********************

Problem Summary:
    You are given a list of activities. 
    Each activity has:
        - a start time
        - an end time
    A person can perform only ONE activity at a time.

Goal:
    Select the maximum number of NON-OVERLAPPING activities.

Greedy Strategy:
    Always choose the activity that ends the earliest.
    Why? 
        Because it leaves the maximum "space" for future activities.

Steps:
    1. Sort all activities by their END time (in increasing order).
    2. Select the first activity (it has the smallest end time).
    3. For each next activity:
            If its start time >= end time of the last selected activity,
            then select it.

This gives the optimal answer!
*/

#include <iostream>
#include <algorithm>

using namespace std;

// Each activity has a start and end time
struct Activity
{
    int start;
    int end;
};

// Comparator used for sorting activities by END time
bool compareByEnd(const Activity &a, const Activity &b)
{
    return a.end < b.end;  // smaller ending time comes first
}

// Just a helper function to display all activities (after sorting)
void print_array(Activity *activities, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << activities[i].start << " " << activities[i].end << endl;
    }
}

/*
    Core function implementing the greedy activity selection.

    LOGIC:
        - The first activity after sorting DEFINITELY has the earliest end time,
          so select it.
        - Keep track of the end time of the last selected activity.
        - For each next activity:
              If its start time >= last end time → SELECT IT.
              Otherwise → skip it (it overlaps).
*/
void solve(Activity *activities, int size)
{
    int selections = 1;                     // We always pick the first activity
    int current_end = activities[0].end;    // End time of the first chosen activity

    for (int i = 1; i < size; i++)
    {
        // If activity does NOT overlap with the previously selected one
        if (activities[i].start >= current_end)
        {
            selections++;                   // Select it
            current_end = activities[i].end; // Update the new "last activity" end time
        }
    }

    cout << selections << endl;             // Print maximum count of activities
}

int main()
{
    // Manually creating a small test case of 6 activities
    Activity activities[6];
    int size = 6;

    activities[0].start = 0;  activities[0].end = 6;
    activities[1].start = 3;  activities[1].end = 4;
    activities[2].start = 1;  activities[2].end = 2;
    activities[3].start = 5;  activities[3].end = 9;
    activities[4].start = 5;  activities[4].end = 7;
    activities[5].start = 8;  activities[5].end = 9;

    // Step 1: Sort by ending time
    sort(activities, activities + size, compareByEnd);

    // Print sorted activities for demonstration
    print_array(activities, size);

    // Step 2: Apply greedy selection
    solve(activities, size);

    return 0;
}
