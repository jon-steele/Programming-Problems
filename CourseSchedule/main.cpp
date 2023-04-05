// https://cses.fi/problemset/task/1679
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

int main() {

    int a, b;
    cin >> n >> m;
    vector<vector<int>> courses(n + 1); // Holds the course dependencies
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        courses[a].push_back(b);
        indegree[b]++;
    }

    queue<int> queue;
    // Getting the roots, adding them first into our queue
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            queue.push(i);
        }
    }

    vector<int> result;
    //BFS through each node
    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();
        result.push_back(current);

        for (int i = 0; i < courses[current].size(); i++) {
            
            int neighbour = courses[current][i];
            
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                queue.push(neighbour);
            }
        }
    }

    if (result.size() != n) {
        cout << "IMPOSSIBLE" << endl;
    } 
    else {
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
