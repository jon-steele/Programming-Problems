// http://www.usaco.org/index.php?page=viewproblem2&cpid=940
#include <iostream>
#include <vector>
using namespace std;

vector<int> stations[101];
bool visited[101];

void dfs(int index) {
    if (visited[index]) 
        return;
    visited[index] = true;

    for (int i = 0; i < stations[index].size(); i++) {
        dfs(stations[index][i]);
    }
}

int main() {
    int n, a, b;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;

        // I'm going to DFS in the reverse direction
        stations[b].push_back(a);
    }

    int result = -1;
    for (int i = 1; i <= n; i++) {

        // DFS for this station
        fill(visited, visited + 101, false);
        dfs(i);

        // Check if we reached all other stations
        bool canReach = true;
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                canReach = false;
                break;
            }
        }

        if (canReach) {
            result = i;
            break;
        }
    }

    cout << result << endl;

    return 0;
}
