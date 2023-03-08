// http://www.usaco.org/index.php?page=viewproblem2&cpid=993
#include <iostream>
#include <set>
#include <vector>
using namespace std; 

int n, m, c;

int main(){
    cin >> n >> m >> c;

    int moonies[n];
    pair<int, int> roads[m];

    for (int i = 0; i < n; i++){
        cin >> moonies[i];
    }

    int a, b;

    for (int i = 0; i < m; i++){
        cin >> a >> b;
        roads[i] = make_pair(a, b);
    }

    // Now, we need to find the shortest path.
    // I'm thinking we use a bfs to iteratively try each path
    // However, this will have a time complexity of 2^n, and we need n^2 or better
    
    
}