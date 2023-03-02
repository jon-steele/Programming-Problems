// https://cses.fi/problemset/task/1635
#include <iostream>
#include <algorithm>
using namespace std;

int n, goal;
int coins[100];
int mod = 1e9+7;

int main() {

    cin >> n >> goal;
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }

    // We can use dynamic programming to find the # of combinations for each preceding value
    int combinations[goal + 1];
    fill(combinations, combinations + goal + 1, 0);
    combinations[0] = 1;

    // Fill our array
    for (int i = 1; i <= goal + 1; i++){
        // For each index, we want to consider using each different coin
        for (int coin = 0; coin < n; coin++){
            // If the coin goes past our goal, we can ignore it
            if (i - coins[coin] < 0)
                continue;
            else {
                combinations[i] = (combinations[i] + combinations[i - coins[coin]]) % mod;
            }
        }
    }

    cout << combinations[goal] << endl;

    return 0;
}