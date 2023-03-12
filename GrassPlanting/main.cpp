// http://www.usaco.org/index.php?page=viewproblem2&cpid=894
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

// Fields will hold the number of edges for each node
vector<int> fields[100005];


int main()
{
    int n, a, b;
    cin >> n;
    memset(fields, 0, sizeof(fields));
    
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        fields[a].push_back(b);
        fields[b].push_back(a);
    }

    // Once we have all the edges, we can find the maximum required types of grass
    int maximum = 0;

    for (int i = 1; i <= n; i++)
    {
        if(fields[i].size() > maximum)
         maximum = fields[i].size();
    }
    
    cout << maximum + 1 << endl;
    
    return 0;
}