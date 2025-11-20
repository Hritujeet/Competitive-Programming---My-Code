/*
You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.
Input
The only input line contains a string of n characters.
Output
Print one integer: the length of the longest repetition.s
*/

#include <iostream>
using namespace std;

void solve(string s)
{
    int maxRep = 1, currentRep = 1;
    
    for (string::size_type i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i-1])
        {
            currentRep ++;
            
            if (currentRep > maxRep)
            {
                maxRep = currentRep;
            }
            
        }
        else {
            currentRep = 1;
        }
    }
    
    cout << maxRep;

}

int main()
{
    string str;
    cin >> str;

    solve(str);
    return 0;
}