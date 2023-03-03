// https://cses.fi/problemset/task/1636
#include <iostream>
#include <cstring>
using namespace std;

int coins[0];
int mod = 1e9+7;

int main(){
    int n, goal;
    cin >> n >> goal;
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int combinations[goal + 1];
    memset(combinations, 0, sizeof(combinations));
    combinations[0] = 1; // Add empty set case
    
    // Because the order doesnt matter, we try exhausting the use of each coin before moving on
    for (int coin = 0; coin < n; coin++){
        for (int i = 1; i <= goal; i++){ // Starts at 1, because we needed the empty set case
            if (i - coins[coin] > -1)
                combinations[i] = (combinations[i] + combinations[i - coins[coin]]) % mod;
        }
    }

    cout << combinations[goal] << endl;
}