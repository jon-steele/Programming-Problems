// https://cses.fi/problemset/task/1674
#include <iostream>
#include <vector>

using namespace std;

// adjacent holds each child node of a given node.
vector<vector<int> > adjacent;
// subordinates holds the number of subordinates for each boss
vector<int> subordinates;

void dfs(int node) {
    for (int child = 0; child < adjacent[node].size(); child++) {
        dfs(adjacent[node][child]);
        subordinates[node]++;
        subordinates[node] += subordinates[adjacent[node][child]];
    }
}

int main() {
    int n;
    cin >> n;
    
    adjacent.resize(n + 1);
    subordinates.resize(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int boss;
        cin >> boss;
        adjacent[boss].push_back(i + 1);
    }

    // dfs will recursively search through the adjacent vector, filling in the subordinate array as it goes. 
    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << subordinates[i] << " ";
    }
    cout << endl;

    return 0;
}
