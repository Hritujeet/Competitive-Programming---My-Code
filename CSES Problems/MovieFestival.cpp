/*
In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?
Input
The first input line has an integer n: the number of movies.
After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.
Output
Print one integer: the maximum number of movies.
*/
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Movie
{
    ll st;
    ll end;
};

bool compareByEnd(const Movie &a, const Movie &b)
{
    return a.end < b.end;
}

void watch_movie(Movie *movies, ll n)
{
    sort(movies, movies + n, compareByEnd);
    ll watched = 1;
    ll current_end = movies[0].end;

    for (ll i = 1; i < n; i++)
    {
        if (movies[i].st >= current_end)
        {
            watched++;
            current_end = movies[i].end;
        }
    }
    cout << watched;
}

int main()
{
    ll n;
    cin >> n;

    Movie *movies = new Movie[n];

    for (ll i = 0; i < n; i++)
    {
        cin >> movies[i].st >> movies[i].end;
    }

    watch_movie(movies, n);

    return 0;
}