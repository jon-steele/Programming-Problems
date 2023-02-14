//http://www.usaco.org/index.php?page=viewproblem2&cpid=785
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int heights[100];
int sorted[100];
int n;

int main()
{
    // Take inputs

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        sorted[i] = heights[i];
    }

    sort(sorted, sorted + n);

    int counter = 0;

    for (int i = 0; i < n; i++){
        if (sorted[i] != heights[i])
            counter++;
    }

    cout << counter - 1 << endl;
}