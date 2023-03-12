// https://cses.fi/problemset/task/1666
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> cities[100005];
bool seen[100005];

void dfs(int x) 
{

    seen[x] = 1;

    for (int i = 0; i < (int) cities[x].size(); i++)
    {
        if (seen[cities[x][i]] == 0) // If we havent seen this city yet
            dfs(cities[x][i]);
    }
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        cities[a].push_back(b);
        cities[b].push_back(a);
    }
    
    // Now we must find the # of disjoint cities, and we have our answer.
    vector<int> groups;

    for (int i = 1; i <= n; i++)
    {
        if (seen[i] == 0){
            dfs(i);
            groups.push_back(i);
        }
    }

    cout << groups.size() - 1 << endl;
    for (int i = 1; i < (int) groups.size(); i++)
    {
        cout << groups[i - 1] << " " << groups[i] << endl;
    }
    
    return 0;
}