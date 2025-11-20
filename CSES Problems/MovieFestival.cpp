/*
In a movie festival, n movies will be shown.
Each movie has a starting time and an ending time.
You want to watch the maximum number of movies fully (no overlaps allowed).

Key idea:
- You can watch a movie only if its start time is >= the end time of the last movie you watched.
- The best greedy strategy is to always pick the movie that ends the earliest.
*/

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

// Structure to store each movie's start and end time.
struct Movie
{
    ll st;
    ll end;
};

// Comparator to sort movies by ending time (ascending order).
// Why? Because picking the movie that ends earliest leaves more room for future movies.
bool compareByEnd(const Movie &a, const Movie &b)
{
    return a.end < b.end;
}

void watch_movie(Movie *movies, ll n)
{
    /*
        STEP 1: Sort all movies by ending time.
        After sorting:
            movies[0] = movie that ends the earliest,
            movies[1] = next earliest ending, and so on.

        This is the classic "Activity Selection Problem" greedy strategy.
    */
    sort(movies, movies + n, compareByEnd);

    /*
        STEP 2: Always pick the first movie because it ends the earliest.
        Initialize:
            watched = 1  (we pick the first movie)
            current_end = movies[0].end  (we must pick future movies whose start >= this)
    */
    ll watched = 1;
    ll current_end = movies[0].end;

    /*
        STEP 3: Loop through the remaining movies and take a movie
                ONLY IF it starts after or exactly when the last one ended.

        Example:
            If last watched movie ended at time 10,
            and the next movie starts at 10 or later → it's valid.
    */
    for (ll i = 1; i < n; i++)
    {
        if (movies[i].st >= current_end)
        {
            watched++;                      // we can watch this movie
            current_end = movies[i].end;    // update the new finishing time
        }
    }

    // Output the maximum number of non-overlapping movies.
    cout << watched;
}

int main()
{
    ll n;
    cin >> n;

    // Dynamically allocate array of movies.
    Movie *movies = new Movie[n];

    // Read all start and end times.
    for (ll i = 0; i < n; i++)
    {
        cin >> movies[i].st >> movies[i].end;
    }

    // Compute and print the answer.
    watch_movie(movies, n);

    return 0;
}
