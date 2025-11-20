/*
You are given a DNA sequence: a string consisting only of A, C, G, and T.

Your task:
    Find the longest repetition — that is, the longest substring where
    the SAME character repeats continuously.

Example:
    Input:  A A A C C G G G G T
    Longest repetition → "GGGG" → length = 4

Approach:
    - Scan the string from left to right.
    - Keep track of:
        currentRep → how long the current sequence of equal characters is.
        maxRep     → maximum repetition seen so far.
*/

#include <iostream>
using namespace std;

void solve(string s)
{
    // If the string has at least 1 character, the minimum repetition is 1.
    int maxRep = 1;
    int currentRep = 1;

    /*
        We start from index 1 and compare each character with the previous one.
        Why?
            Because repetition means: s[i] == s[i-1]
    */
    for (string::size_type i = 1; i < s.size(); i++)
    {
        // If current char matches previous → repetition continues
        if (s[i] == s[i - 1])
        {
            currentRep++;                     // extend current repeating streak

            // Update the longest streak seen so far
            if (currentRep > maxRep)
            {
                maxRep = currentRep;
            }
        }
        else
        {
            /*
                If characters differ,
                the repetition chain breaks → reset currentRep back to 1.
            */
            currentRep = 1;
        }
    }

    // Print the longest chain of identical characters
    cout << maxRep;
}

int main()
{
    string str;
    cin >> str;

    solve(str);
    return 0;
}
