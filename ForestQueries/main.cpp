//https://cses.fi/problemset/task/1652/
#include <iostream>
#include <vector>
using namespace std;

int forest[1001][1001];

int main(){

    int n = 0, q, y, x;
    char c;

    cin >> n >> q;

    int answers[q];
    cin.get(c);

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < n + 2; j++){
            cin.get(c);
            if (c == '\n')
                break;
            else
                forest[i][j] = (c == '*') ? 1 : 0;
        }
    }

    // Creating the prefix sum;
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < n + 1; j++){
            forest[i][j] += forest[i][j - 1];
        }
    }

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < n + 1; j++){
            forest[j][i] += forest[j - 1][i];
        }
    }
    
    int y1, x1, y2, x2;
    int ans;

    for (int i = 0; i < q; i++){
        cin >> y1 >> x1 >> y2 >> x2;
        ans = forest[y2][x2] - forest[y1 - 1][x2] - forest[y2][x1 - 1] + forest[y1 - 1][x1 - 1];
        answers[i] = ans;
    }

    // for (int j = 1; j < n + 1; j++){
    //     for (int i = 1; i < n + 1; i++){
    //         cout << forest[j][i];
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < q; i++){
        cout << answers[i] << endl;
    }
}