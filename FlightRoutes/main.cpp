// https://cses.fi/problemset/task/1682
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> cities[100001];
vector<int> cities_reverse[100001];
bool visited[100001];

void dfs(int index, vector<int> graph[]) {
    if (visited[index]) return;
    visited[index] = true;

    for (int i = 0; i < graph[index].size(); i++) {
        dfs(graph[index][i], graph);
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cities[a].push_back(b);
        cities_reverse[b].push_back(a);
    }

    // Perform DFS from the first city
    dfs(1, cities);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << "1 " << i << endl;
            return 0;
        }
    }

    memset(visited, 0, sizeof(visited));

    // Perform DFS from the first city using the reversed graph
    dfs(1, cities_reverse);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << i << " 1" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
