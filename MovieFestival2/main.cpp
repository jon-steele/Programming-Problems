//https://cses.fi/problemset/task/1632/
#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;
vector<pair<int, int> > movies;

bool compare(pair<int, int> &a, pair<int, int> &b){
    return(a.second < b.second);
}

int main(){
    
    cin >> n >> k;

    int s, e;

    for (int i = 0; i < n; i++){
        cin >> s >> e;
        movies.push_back(make_pair(s, e));
    }

    // Sort by end times
    sort(movies.begin(), movies.end(), compare); 

    int counter = 0;
    int time = 0;

    // Watching holds each individual who is watching a movie, with its start-time
    priority_queue<int> watching;

    for (int i = 0; i < n; i++){

        // We take a look at each start time
        time = movies[i].first;

        // Remove the first person who is finished their movie
        if (watching.size() > 0 && watching.top() * -1 <= time){
            watching.pop();
        }

        // If we have someone available, we watch the movie
        if (watching.size() < k){
            watching.push(movies[i].second * -1);
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}