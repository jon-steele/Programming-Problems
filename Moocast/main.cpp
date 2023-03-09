// http://www.usaco.org/index.php?page=viewproblem2&cpid=668
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

int n;
pair<int, int> nodes[201];
int power[201];

int visited[201];
vector<int> frontier;

int reaches(int x){

    // Setting up arrays
    memset(visited, 0, sizeof(visited));
    frontier.clear();
    frontier.push_back(x);
    visited[x] = true;
    
    // Setting up variables
    double distance = 0;
    double xs = 0;
    double ys = 0;
    int counter = 1;
    bool cont = 1;
    int parent = x;

    while (frontier.size() > 0){

        parent = frontier.back();
        frontier.pop_back();

        // For each node, we check its distance to the originating node
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == true)
                continue;

            // Finding the straight line distance between two nodes
            xs = pow(abs(nodes[parent].first - nodes[i].first), 2);
            ys = pow(abs(nodes[parent].second - nodes[i].second), 2);
            distance = pow(xs + ys, 0.5);

            // If we can reach the node from the parent node
            if (distance <= power[parent])
            {
                // We visit it, and continue on
                visited[i] = true;
                counter++;
                frontier.push_back(i);
            }
        }
    }
    return counter;
}

int main()
{
    cin >> n;
    memset(power, 0, sizeof(power));
    memset(nodes, 0, sizeof(nodes));
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i].first >> nodes[i].second >> power[i];
    }

    int curr = 0;
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        curr = reaches(i);
        if (curr > max)
            max = curr;
    }
    
    cout << max << endl;
    
    return 0;
}