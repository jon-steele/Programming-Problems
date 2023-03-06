#include<iostream>
#include<cstring>
using namespace std;

int mod = 1e9+7;

int main()
{
    int n;
    cin >> n;
    int ways[n];
    memset(ways, 0, sizeof(ways));

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j < 0)
                continue;
            
            ways[i] = (ways[i] + ways[i - j]) % mod;
        }
        
    }
    

    return 0;
}