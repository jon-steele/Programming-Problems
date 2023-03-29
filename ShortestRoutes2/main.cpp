// https://cses.fi/problemset/task/1672
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const long long INF = 1e18;

int main() {
    int n, m, q, a, b, c;
    cin >> n >> m >> q;

    vector<vector<long long>> distance(n + 1, vector<long long>(n + 1, INF));

    // Initialize the pairs that are identical
    for (int i = 1; i <= n; ++i) {
        distance[i][i] = 0;
    }

    // Begin filling in the matrix
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        distance[a][b] = min(distance[a][b], (long long)c);
        distance[b][a] = min(distance[b][a], (long long)c);
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // We check if we have a smaller distance
                if (distance[i][k] != INF && distance[k][j] != INF) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (distance[a][b] == INF) {
            cout << -1 << endl;
        } else {
            cout << distance[a][b] << endl;
        }
    }

    return 0;
}
