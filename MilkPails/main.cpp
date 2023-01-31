#include <iostream>
using namespace std;

int x, y, m, maximum;

int main(){

    maximum = 0;

    cin >> x >> y >> m;

    //N denotes the absolute minimum needed buckets to reach m
    int n = m / x;
    n++;

    //Now we must generate all possible permutations
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            pair<int, int> p = make_pair(i,j);
            
            if ((x * i) + (y * j) <= m)
                maximum = max(maximum, (x * i) + (y * j));
        }
    }

    cout << maximum;
}