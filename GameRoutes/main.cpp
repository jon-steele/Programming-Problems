// https://cses.fi/problemset/task/1681
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int n, m;
int mod = 1e9 + 7;
vector<int> teleporters[100005];
int dp[100005];
int indeg[100005];
bool seen[100005];

void dfs(int v) {
    seen[v] = 1;
    for (auto child : teleporters[v]) {
        if (seen[child] == 0)
            dfs(child);
    }
}

// removeme removes a given vertex from it's child nodes vertices
void removeme(int v) {
    for (auto child : teleporters[v]) {
        indeg[child]--;
    }
}

int main()
{
    cin >> n >> m;

    memset(dp, 0, sizeof(dp));
    memset(indeg, 0, sizeof(indeg));
    memset(seen, 0, sizeof(seen));

    int a, b;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        teleporters[a].push_back(b);
        indeg[b]++;
    }

    // We are going to do a DFS from vertex 1, to determine which nodes 
    // Are reachable. All other nodes should be ignored. 
    dfs(1);
    
    // To remove the non - reachable nodes from our graph, we can dfs on the roots
    for (int i = 2; i <= n; i++)
    {
        // If the vertex is not seen, we need to make the child nodes indegree 1 less.
        if (seen[i] == 0) {
            removeme(i);
        }
    }
    
    dp[1] = 1;
    queue<int> q;
    q.push(1);
    int vertex;

    // BFS Fashioned Colouring
    while(!q.empty()){

        vertex = q.front();
        q.pop();

        for (auto child : teleporters[vertex]) {

            dp[child] = (dp[vertex] + dp[child]) % mod; // increase the child's incoming possibilities
            indeg[child]--; // decrease the child's incoming edges

            if (indeg[child] == 0) // I only want to visit the child if there are no more parent nodes.
                q.push(child);
        }
    }

    cout << dp[n] << endl;

    return 0;
}