// https://cses.fi/problemset/task/1193
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<tuple>

using namespace std;

string graph[1001];
int cost[1001][1001];
int y, x;
pair<int, int> start;
pair<int, int> finish;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
int prev_dir[1001][1001];

bool grassfire()
{
    queue<pair<int, int>> q;
    q.push(start);
    cost[start.first][start.second] = 0;

    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (a == finish.first && b == finish.second)
            return true;

        for (int i = 0; i < 4; i++)
        {
            int new_a = a + dx[i];
            int new_b = b + dy[i];

            if (new_a >= 0 && new_a < y && new_b >= 0 && new_b < x && cost[new_a][new_b] == -1 && graph[new_a][new_b] != '#')
            {
                cost[new_a][new_b] = cost[a][b] + 1;
                prev_dir[new_a][new_b] = i;
                q.push(make_pair(new_a, new_b));
            }
        }
    }

    return false;
}

void inputs()
{
    cin >> y >> x;
    memset(cost, -1, sizeof(cost));
    for (int i = 0; i < y; i++)
    {
        cin >> graph[i];
        for (int j = 0; j < x; j++)
        {
            if (graph[i][j] == 'A')
                start = make_pair(i, j);
            if (graph[i][j] == 'B')
                finish = make_pair(i, j);
        }
    }
}

string backtrack()
{
    string path = "";
    int a = finish.first;
    int b = finish.second;

    while (make_pair(a, b) != start)
    {
        int d = prev_dir[a][b];
        path = dir[d] + path;
        a -= dx[d];
        b -= dy[d];
    }

    return path;
}

int main()
{
    inputs();

    if (grassfire())
    {
        cout << "YES" << endl << cost[finish.first][finish.second] << endl;
        cout << backtrack() << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}
