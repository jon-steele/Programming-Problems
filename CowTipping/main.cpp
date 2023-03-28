//http://www.usaco.org/index.php?page=viewproblem2&cpid=689
#include<iostream>
#include <string>
using namespace std;

int n;
int cows[10][10];

//Furthest cow will return the coordinates(row, col) of the furthes cow from 0,0
pair<int, int> furthestCow() 
{
    pair<int, int> coords = make_pair(0, 0);
    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cows[i][j] == 1 && i + j > maximum)
            {
                maximum = i + j;
                coords = make_pair(i, j);
            }
        }
    }
    return coords;
}

// Flip will flip all the bits from a given cooridnate to the top left cooridnate, in a rectangle
void flip(int row, int col)
{
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            if (cows[i][j] == 1)
            {
                cows[i][j] = 0;
            }
            else
            {
                cows[i][j] = 1;
            }
        }
    }
}

int main()
{
    cin >> n;
    string row = "";

    for (int i = 0; i < n; i++)
    {
        cin >> row;
        for (int j = 0; j < n; j++)
        {
            cows[i][j] = (int)(row[j]) - 48;
        }
    }

    // To start, we need to find the furthest cow from the top left square. This is because we inevitably need to flip him,
    // and may as well get it done with right away.
    int counter = 0;
    pair<int, int> furthest = furthestCow();
    while(!(furthest.first == 0 && furthest.second == 0))
    {
        flip(furthest.first, furthest.second);
        counter++;
        furthest = furthestCow();
        if (furthest.first == 0 && furthest.second == 0)
            break;
    }

    if (cows[0][0] == 1)
        counter++;
    
    cout << counter << endl;
}