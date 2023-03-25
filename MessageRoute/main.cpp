// https://cses.fi/problemset/task/1667
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
vector<vector<int> > adjacencies;
int visited[100001];
int parent[100001];

//bfs will find the shortest path first
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int child : adjacencies[current]) {
            if (!visited[child]) {
                visited[child] = 1;
                parent[child] = current;
                q.push(child);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    adjacencies.resize(n + 1);
    memset(visited, 0, sizeof(visited));
    memset(parent, 0, sizeof(parent));

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adjacencies[a].push_back(b);
        adjacencies[b].push_back(a);
    }

    bfs(1);

    if (visited[n]) {
        vector<int> path;
        int currentNode = n;
        while (currentNode) {
            path.push_back(currentNode);
            currentNode = parent[currentNode];
        }

        cout << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
    } 
    else 
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
