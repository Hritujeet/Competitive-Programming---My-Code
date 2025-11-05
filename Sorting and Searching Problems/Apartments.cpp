/*
Problem: Apartment Allotment (CSES Problem Set)
Objective: Maximize the number of applicants who receive an apartment, where an applicant accepts any apartment size within k units of their desired size.
Input: n (applicants), m (apartments), k (max difference). Arrays 'aplicants' and 'apartments'.
Output: The maximum number of successful allotments.
*/

#include <iostream>
#include <vector>
#include <algorithm>
// Include <cmath> for llabs if using the alternative absolute difference check, 
// but the current inclusive range check is sufficient and correct.

using namespace std;
typedef long long ll;

int allotment_apartments(vector<ll> &aplicants, vector<ll> &apartments, ll k)
{
    /*
    This problem is solved using a **Greedy Two-Pointer** approach. 
    The core idea relies on the observation that matching the smallest possible applicant 
    with the smallest possible acceptable apartment size leads to a globally optimal solution. 
    By processing sizes in increasing order, we "save" larger apartments for larger applicants 
    who might have fewer options, thus maximizing the overall count.
    */
    
    // Step 1: Sorting is crucial for the two-pointer technique.
    // We sort both lists to ensure we are always looking at the smallest unassigned
    // applicant (i) and the smallest unassigned apartment (j) in each iteration.
    sort(aplicants.begin(), aplicants.end());
    sort(apartments.begin(), apartments.end());

    ll i = 0; // Pointer for the applicants array (smallest unassigned desired size)
    ll j = 0; // Pointer for the apartments array (smallest unassigned available size)
    ll allotted_apartments = 0; // Counter for the total number of successful matches

    // Step 2: Main Two-Pointer Loop
    // The loop continues as long as there are both applicants and apartments left to consider.
    while (i < aplicants.size() && j < apartments.size())
    {
        // Define the current desired size (A) and available size (B) for readability
        ll desired_size = aplicants[i];
        ll apartment_size = apartments[j];

        // Case 1: Match Found - The apartment size is within the acceptable range [A_i - k, A_i + k].
        // This is the locally optimal choice: take the match now and move on.
        if (apartment_size <= desired_size + k && apartment_size >= desired_size - k)
        {
            allotted_apartments++; // Successfully allotted.
            j++;                   // Move to the next apartment (this one is taken).
            i++;                   // Move to the next applicant (this one is satisfied).
        }
        
        // Case 2: Apartment Too Small (apartment_size < desired_size - k)
        // The current apartment is too small for the current applicant 'i'.
        else if (apartment_size < desired_size - k)
        {
            // We must discard this apartment (j++). Since the apartments array is sorted, 
            // this small apartment will also be too small for *all* subsequent applicants 
            // (i+1, i+2, ...) whose desired sizes are greater than or equal to A_i.
            j++;
            // Applicant 'i' remains to see if a larger apartment (j+1) will suit them.
        }

        // Case 3: Apartment Too Large (The remaining condition: apartment_size > desired_size + k)
        // The current apartment is too large for the current applicant 'i'.
        else // apartment_size > desired_size + k
        {
            // We must discard this applicant (i++). We keep the current apartment (j) saved. 
            // The current apartment might be a perfect fit for the next applicant (i+1, i+2, ...) 
            // who will have an equal or larger desired size.
            i++;
            // Apartment 'j' remains to be matched against the next applicant.
        }
    }
    return allotted_apartments;
}

int main()
{
    // Standard input reading for n, m, and k.
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> aplicants, apartments;

    // Reading applicant desired sizes
    for (int idx = 0; idx < n; idx++)
    {
        ll inp;
        cin >> inp;
        aplicants.push_back(inp);
    }

    // Reading apartment available sizes
    for (int idx = 0; idx < m; idx++)
    {
        ll inp;
        cin >> inp;
        apartments.push_back(inp);
    }

    // Call the core function and print the final maximum count.
    cout << allotment_apartments(aplicants, apartments, k);

    return 0;
}