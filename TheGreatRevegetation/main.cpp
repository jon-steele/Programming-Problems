// http://www.usaco.org/index.php?page=viewproblem2&cpid=920
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<char, int>> pastures[200002];
vector<bool> visited;
vector<int> color;

// dfs will check if the component is bitartite or not
bool dfs(int node, int c) {
    visited[node] = true;
    color[node] = c;

    for (const auto &edge : pastures[node]) {
        int neighbor = edge.second;
        char type = edge.first;

        if (!visited[neighbor]) {
            // If we have a same type edge, use the current colour, otherwise switch the colour
            int next_color = (type == 'S') ? c : 1 - c;
            if (!dfs(neighbor, next_color)) {
                return false;
            }
        } 
        
        else {
            // If the edge is of the same type and the colors don't match, 
            // or if the edge is of a different type and the colors match, 
            // then it's not bipartite
            if ((type == 'S' && color[node] != color[neighbor]) || (type == 'D' && color[node] == color[neighbor])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    visited.resize(n + 1, false);
    color.resize(n + 1, -1);

    int a, b;
    char t;
    for (int i = 0; i < m; i++) {
        cin >> t >> a >> b;
        pastures[a].push_back(make_pair(t, b));
        pastures[b].push_back(make_pair(t, a));
    }

    // For each sub component, we can have either 2, or 0 ways of coloring the graph. 
    // There are 2 ways to color a sub component if it is a bipartite sub component. 
    // There are 0 otherwise. 

    int components = 0;

    // For each subcomponent
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {

            // If we find that the graph is not bipartite, we have our answer
            if (!dfs(i, 0)) {
                cout << 0 << endl;
                return 0;
            }
            components++;
        }
    }

    // Because each component doubles the number of combinations, we only need the first one, followed by the correct
    // number of zeroes
    string result = "1";
    for (int i = 0; i < components; i++) {
        result += "0";
    }

    cout << result << endl;

    return 0;
}
