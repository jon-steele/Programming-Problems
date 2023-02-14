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

    for (int i = 0; i < n; i++){
        cin >> s >> e;
        movies.push_back(make_pair(s, e));
    }

    sort(movies.begin(), movies.end(), compare); 

    return 0;
}