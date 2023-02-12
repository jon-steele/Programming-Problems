//https://codeforces.com/contest/863/problem/B
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int n;

int main()
{
    cin >> n;
    int weights[2 * n];
    for (int i = 0; i < 2*n; i++)
    {
        cin >> weights[i];
    }
    sort(weights, weights + 2 * n);

    int instability = 0;
    int min_instability = 1e9;

    // Iterate through each possible pair of kayakers removed
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = i + 1; j < 2 * n; j++)
        {
            instability = 0;
            int k = 0;

            // For each pair, we calculate the instability, excluding the two kayakers
            while(k < 2 * n - 1){
                if (k == i || k == j){
                    k++;
                }
                else{
                    instability += abs(weights[k] - weights[k + 1]);
                    k += 2;
                }
            }
            min_instability = min(instability, min_instability);
        }
    }

    cout << min_instability << endl;
    
    return 0;
}