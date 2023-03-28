// https://cses.fi/problemset/task/1671
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> cities;
long long distances[100001];
bool visited[100001];

void dijkstra(int city) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> frontier;
    frontier.push(make_pair(0, city));
    distances[city] = 0;

    while (!frontier.empty()) {
        int next = frontier.top().second;
        frontier.pop();

        if (visited[next]) {
            continue;
        }
        visited[next] = true;

        for (auto& child : cities[next]) {
            int nextCity = child.first;
            long long nextDist = child.second;

            if (distances[next] + nextDist < distances[nextCity]) {
                distances[nextCity] = distances[next] + nextDist;
                frontier.push(make_pair(distances[nextCity], nextCity));
            }
        }
    }
}

int main() {
    long long n, m, a, b, c;
    cin >> n >> m;
    cities.resize(n + 1);

    memset(distances, 0x3f, sizeof(distances));

    for (long long i = 0; i < m; i++) {
        cin >> a >> b >> c;
        cities[a].push_back(make_pair(b, c));
    }

    dijkstra(1);

    for (long long i = 1; i <= n; i++) {
        cout << distances[i] << " ";
    }
    cout << endl;

    return 0;
}
