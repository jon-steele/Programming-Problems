//https://cses.fi/problemset/task/1632/
#include<iostream>
#include<vector>
#include <algorithm>
#include <set>
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

    // Set will keep track of the people watching movies, in sorted order
    set<pair<int, int> > watching;
    int counter = 0;

    for (int i = 0; i < n; i++){

        // If nobody is watching, we can assign them to the current movie
        if (watching.size() == 0)
            watching.insert({movies[i].second * -1, i});

        else {

            // Update our time to the start of the current movie
            auto time = watching.lower_bound({movies[i].first * -1, -1});
            
            // If the two movies start and end times do not overlap
            if (time != watching.end()) {
                watching.erase(time);
                watching.insert({movies[i].first * -1, -1});
            }
        
            // If they do overlap, but we have an extra person, we can watch
            else if (time == watching.end() && watching.size() < k)
                watching.insert({movies[i].second * -1, i});
            
            // We cant watch the movie
            else
                counter++;
        }
    }

    cout << n - counter;
}