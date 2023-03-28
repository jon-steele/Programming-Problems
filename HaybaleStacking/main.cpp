//http://www.usaco.org/index.php?page=viewproblem2&cpid=104
#include <iostream>
#include <algorithm>

using namespace std;

int n, k;

int main() {

    cin >> n >> k;
    int haybales[n];
    fill(haybales, haybales + n, 0);

    int start, end;

    for (int i = 0; i < k; i++){
        cin >> start >> end;
        haybales[start]++;
        haybales[end + 1]--;
    }

    // Sum all of the bales
    for (int i = 1; i < n; i++){
        haybales[i] = haybales[i] + haybales[i - 1];
    }

    //Now sort them, and we have the median
    sort(haybales, haybales + n);

    cout << haybales[(n - 1) / 2] << endl;
}