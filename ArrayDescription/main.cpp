// https://cses.fi/problemset/task/1746
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int mod = 1e9+7;

int main()
{
    int n, m;
    int counter = 0;
    cin >> n >> m;
    int array[n + 1];
    memset(array, 0, sizeof(array));
    array[0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> array[i];
    }

    int combinations[n + 1];
    memset(combinations, 0, sizeof(combinations));
    combinations[0] = 1;
    int diff = 0;

    for (int i = 1; i < n + 1; i++)
    {
        if (array[i] != 0)
            combinations[i] = combinations[i - 1];
        
        // Because the maximum difference between adjacent values can be at most one, we must be careful
        // At most, an empty cell can vary by 3
        else
        {
            // End case
            if (i == n)
            {
                if (array[i - 1] == m || array[i - 1] == 1)
                    combinations[i] = (combinations[i - 1] * 2) % mod;
                else
                    combinations[i] = (combinations[i - 1] * 3) % mod;
            }

            // Start case
            if (i == 1)
            {
                if (array[i + 1] == m || array[i + 1] == 1)
                    combinations[i] = 2;
                else
                    combinations[i] = 3;
            }
            
            // Normal case
            else
            {
                diff = abs(array[i - 1] - array[i + 1]);
                
                if (diff == 2)
                    combinations[i] = (combinations[i - 1] * 1) % mod;
                else if (diff == 1)
                    combinations[i] = (combinations[i - 1] * 2) % mod;
                else if (diff == 1)
                    combinations[i] = (combinations[i - 1] * 3) % mod;
                
            }
        }
    }
    
    cout << combinations[n] << endl;
    return 0;
}