#include <bits/stdc++.h>
using namespace std;
 
vector<int> graph[5001];
int n, m;

int shortest_cycle(int n)
{
    int minimum = INT_MAX; // Minimum cycle
    
    // Checking each vertex, considering it as the start of our cycle
    for (int i = 0; i < n; i++) {
 
        vector<int> distance(n, (int)(1e9));
        vector<int> parent(n, -1);
        distance[i] = 0;
        queue<int> q;
 
        q.push(i);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int child : graph[x]) {
 
                if (distance[child] == (int)(1e9)) {
                    distance[child] = 1 + distance[x];
                    parent[child] = x;
                    q.push(child);
                }
 
                // If it is visited, we may update our shortest cycle
                else if (parent[x] != child and parent[child] != x)
                    minimum = min(minimum, distance[x] + distance[child] + 1);
            }
        }
    }
 
    if (minimum == INT_MAX)
        return -1;
    else
        return minimum;
}

int main()
{
    cin >> n >> m;
    int x, y;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }

    cout << shortest_cycle(n) << endl;
 
    return 0;
}