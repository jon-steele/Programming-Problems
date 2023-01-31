//Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=568
#include <iostream>
#include <vector>
using namespace std;
//n road rules
//m bessie
int n, m;
vector<pair<int, int> > road;
vector<pair<int, int> > bessie;

int main() {

    cin >> n >> m;

    road.push_back(make_pair(0,0));
    bessie.push_back(make_pair(0,0));

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        road.push_back(make_pair(x, y));
    }

    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        bessie.push_back(make_pair(x, y));
    }

    int maximumOverSpeed = 0;
    int limitPointer = 0;
    int bessiePointer = 0;
    int limitCounter = road[0].first;
    int bessieCounter = bessie[0].second;

    for (int i = 1; i <= 100; i++){
        
        int limit, actual;

        //If this road segment, i, has surpassed the road segment in which
        //bessiePointer is pointing to, we need to update.
        if (i > bessieCounter){
            bessiePointer++;
            bessieCounter = bessieCounter + bessie[bessiePointer].first;
        }

        //same with the posted speed limits
        if (i > limitCounter){
            limitPointer++;
            limitCounter = limitCounter + road[limitPointer].first;
        }

        limit = road[limitPointer].second;
        actual = bessie[bessiePointer].second;

        //Once we have both the speed bessie was travelling, and the actual speed limit for this mile,
        //We can compare it to the maximum seen so far.

        maximumOverSpeed = max(maximumOverSpeed, actual - limit);
    }


    cout << maximumOverSpeed;
}