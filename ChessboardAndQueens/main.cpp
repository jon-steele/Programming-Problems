//Problem: https://cses.fi/problemset/task/1624
#include <iostream>
#include <vector>
using namespace std;

char chessboard[8][8];
bool queens[8][8];
int c;
bool diagonalLeft[15], diagonalRight[15], column[8];

//There are 15 diagonal lines to be filled

// 1  2  3  4  5  6  7  8
// 1  2  3  4  5  6  7  8
// 1  2  3  4  5  6  7  8
// 1  2  3  4  5  6  7  8
// 1  2  3  4  5  6  7  8
// 1  2  3  4  5  6  7  8
// 1  2  3  4  5  6  7  8
// 1  2  3  4  5  6  7  8


//Search moves through each row, recursively finding all solutions
void search(int row){

    //If this search reaches row 8, we know we have reached a solution and can iterate count
    if (row == 8){
        c++;
        return;
    }

    for (int col = 0; col < 8; col++){

        //If this queen lies in the same column, or diagonal line as another, we cannot place her in this 
        //row and column. So, we consider the next column over. 
        if (chessboard[row][col] == '*' || diagonalLeft[row + col] == 1 || diagonalRight[row - col + 7] == 1 || column[col] == 1){
            continue;
        }

            //Since this is a viable spot, we place her here and consider the possibilities
            diagonalLeft[row + col] = 1;
            diagonalRight[row - col + 7] = 1;
            column[col] = 1;
            queens[row][col] = true;

            search(row + 1);

            queens[row][col] = false;
            //Once we have considered placing her here, we must consider the case if we never placed her here too
            diagonalLeft[row + col] = 0;
            diagonalRight[row - col + 7] = 0;
            column[col] = 0;
    }

}

int main() {
    
    c = 0;

    for (int i = 0; i < 8; i++){
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++){
            chessboard[i][j] = s.at(j);
        }
    }

    search(0);

    cout << c;
}