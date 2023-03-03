// https://cses.fi/problemset/task/1639
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    int matrix[s1.length() + 1][s2.length() + 1];
    memset(matrix, 0, sizeof(matrix));

    for (int i = 0; i < s1.length() + 1; i++){
        matrix[i][0] = i;
    }

    for (int i = 0; i < s2.length() + 1; i++){
        matrix[0][i] = i;
    }

    for (int row = 1; row < s1.length() + 1; row++){
        for (int col = 1; col < s2.length() + 1; col++){
            // 2 cases
            // Elements match
            if (s1[row - 1] == s2[col - 1]) {
                matrix[row][col] = matrix[row - 1][col - 1];
            }
            // Elements don't match
            else {
                matrix[row][col] = min(min(matrix[row - 1][col], matrix[row][col - 1]), matrix[row - 1][col - 1]) + 1;
            }
        }
    }

    // for (int row = 0; row < s1.length() + 1; row++){
    //     for (int col = 0; col < s2.length() + 1; col++){
    //         cout << matrix[row][col];
    //     }
    //     cout << endl;
    // }

    cout << matrix[s1.length()][s2.length()];
}