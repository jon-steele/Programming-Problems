// http://www.usaco.org/index.php?page=viewproblem2&cpid=944
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> groups[100001];
pair<int, int> coords[100001];
vector<int> connections[100001];
bool visited[100001];

void dfs(int group, int index){
    if (visited[index] == 0) {

        visited[index] = 1;
        groups[group].push_back(index);

        for (int i = 0; i < connections[index].size(); i++)
        {
            dfs(group, connections[index][i]);
        }
    }
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> coords[i].first >> coords[i].second;
    }
    
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        connections[a - 1].push_back(b - 1);
        connections[b - 1].push_back(a - 1);
    }
    
    // Once we have all the cows and their connections, we need to BFS and generate each group

    int group = 0;
    int total_groups = 0;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(total_groups, i);
            total_groups++;
        }
    }
    
    // Now we will have several groups of disjoint sets of cows. 
    // The answer is simply the perimiter of the smallest sized field of cows

    // Find the two cows of greatest vertical distance
    // And find the two cows of greatest horizontal distance
    int minx = 1e9;
    int miny = 1e9;
    int maxx = -1;
    int maxy = -1;

    int min_perimeter = 2147483647;
    int perimeter = 0;

    pair<int, int> current;
    for (int i = 0; i < total_groups; i++)
    {
        minx = 1e9;
        miny = 1e9;
        maxx = 0;
        maxy = 0;

        for (int j = 0; j < groups[i].size(); j++)
        {
            // cout << groups[i][j];

            current = coords[groups[i][j]];
            if (current.first > maxx)
                maxx = current.first;
            if (current.first < minx)
                minx = current.first;
            if (current.second > maxy)
                maxy = current.second;
            if (current.second < miny)
                miny = current.second;
        }

        // cout << endl;

        perimeter = 2 * ((maxx - minx) + (maxy - miny));
        if (perimeter < min_perimeter)
            min_perimeter = perimeter;
    }
    

    cout << min_perimeter << endl;
    return 0;
}