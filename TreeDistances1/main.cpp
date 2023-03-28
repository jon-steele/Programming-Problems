// https://cses.fi/problemset/task/1132
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
vector<int> tree[200002];
int result[200002];

void dfs(int node, int parent, int depth) {
    result[node] = depth;
    for (int i = 0; i < tree[node].size(); i++) {
        int child = tree[node][i];
        if (child != parent) {
            dfs(child, node, depth + 1);
        }
    }
}

int main() {

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // First DFS pass to find the farthest node from node 1
    memset(result, 0, sizeof(result));
    dfs(1, -1, 0);

    int farthest_node = max_element(result + 1, result + n + 1) - result;
    // Second DFS pass to find the maximum distance from the farthest node
    memset(result, 0, sizeof(result));
    dfs(farthest_node, -1, 0);

    int max_distance = *max_element(result + 1, result + n + 1);
    // Final DFS pass to calculate the result for each node
    dfs(farthest_node, -1, 0);

    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
