#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int n, k;
vector<pair<int, int> > movies;

bool compare(pair<int, int> &a, pair<int, int> &b){
    return(a.second, b.second);
}

int main(){
    
    cin >> n >> k;

    int s, e;
    int maximum = 0;

    for (int i = 0; i < n; i++){
        cin >> s >> e;
        maximum = max(maximum, e);
        movies.push_back(make_pair(s, e));
    }

    sort(movies.begin(), movies.end(), compare); 

    int free = k;
    int occupied = 0;

    for (int i = 0; i < maximum; i++){
        
    }

    return 0;
}