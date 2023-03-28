#include<iostream>
#include<cstring>
using namespace std;

int mod = 1e9+7;

int main()
{
    int n;
    cin >> n;
    int ways[n + 1];
    memset(ways, 0, sizeof(ways));
    ways[0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j < 0)
                continue;
            
            ways[i] = (ways[i] + ways[i - j]) % mod;
        }
    }
    
    cout << ways[n] << endl;
    return 0;
}