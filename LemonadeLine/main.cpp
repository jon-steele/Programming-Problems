//http://www.usaco.org/index.php?page=viewproblem2&cpid=835
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> line;

int main()
{   
    cin >> n;

    int input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        line.push_back(input);
    }

    sort(line.begin(), line.end());
    reverse(line.begin(), line.end());
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        if (i > line[i])
        {
            counter = counter;
        }
        else
        {
            counter++;
        }
    }
    
    cout << counter << endl;

    return 0;
}