// https://cses.fi/problemset/task/1638
#include<iostream>
#include<cstring>
using namespace std;

int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int matrix[n + 1][n + 1];
    memset(matrix, 0, sizeof(matrix));

    string s = "";
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if(s[j] == '*')
                matrix[i + 1][j + 1] = -1;
        }
    }

    if (matrix[1][1] == 0)
        matrix[1][1] = 1;

    for (int row = 1; row < n + 1; row++)
    {
        for (int col = 1; col < n + 1; col++)
        {
            if (matrix[row][col] == -1)
                continue;

            if (matrix[row][col - 1] == -1 && matrix[row - 1][col] == -1)
                continue;
            else if (matrix[row - 1][col] == -1)
               matrix[row][col] = (matrix[row][col] + matrix[row][col - 1]) % mod;
            else if (matrix[row][col - 1] == -1)
               matrix[row][col] = (matrix[row][col] + matrix[row - 1][col]) % mod;
            else
               matrix[row][col] = (matrix[row][col] + matrix[row - 1][col] + matrix[row][col - 1]) % mod;
        }
    }

    if (matrix[1][1] == -1 || matrix[n][n] == -1)
        cout << 0 << endl;
    else
        cout << matrix[n][n] << endl;
    
    return 0;
}