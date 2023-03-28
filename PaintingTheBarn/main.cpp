//http://www.usaco.org/index.php?page=viewproblem2&cpid=919
#include <iostream>
using namespace std;

int main(){

    int n, k;
    int x1, y1, x2, y2;
    int wall[1001][1001] = {0};

    cin >> n >> k;

    // Looping through, taking in inputs, one square at a time

    for (int i = 0; i < n; i++){

        cin >> x1 >> y1 >> x2 >> y2;
        
        x2--;
        y2--;

        int length = y2 - y1 + 1;
        
        //          x2y2
        // 1       -1
        // 1       -1
        // 1       -1
        // 1       -1
        // x1y1

        // We increment the first side by one, and decrement the second side (plus 1) by one.

        for (int j = 0; j < length; j++){
            wall[y1 + j][x1]++;
        }
        
        for (int k = 0; k < length; k++){
            wall[y2 - k][x2 + 1]--;
        }
    }

    // Now we prefix sum each row, and count the numer of k squares

    int counter = 0;

    for (int y = 0; y < 1001; y++){
        for (int x = 0; x < 1001; x++){
            if (wall[y][x] == k)
                counter++;
            wall[y][x+1] += wall[y][x];
        }
    }
    cout << counter << endl;
}
