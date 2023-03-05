#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int first[n];
    int second[n];
    for (int i = 0; i < n; i++)
    {
        cin >> first[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> second[i];
    }

    int matrix[n + 1][n + 1];
    memset(matrix, 0, sizeof(matrix));
    
    for (int row = 1; row < n + 1; row++)
    {
        for (int col = 1; col < n + 1; col++)
        {
            if (first[row - 1] == second[col - 1])
                matrix[row][col] = max(matrix[row - 1][col], matrix[row][col - 1]) + 1;
            else
                matrix[row][col] = max(matrix[row - 1][col], matrix[row][col - 1]);
        }
    }

    cout << matrix[n][n] << endl;    

    return 0;
}