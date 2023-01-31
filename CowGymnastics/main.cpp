//Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=963
#include <iostream>

using namespace std;

int k, n;
int c = 0;
int cows[10][20];

//Consistent will return a boolean value, indicating whether
//Cow a and cow b were consistent in training, when compared
//to one another.
bool consistent(int a, int b){

    int firstCow = 0;

    //First we get a baseline from row 0
    for (int i = 0; i < n; i++){
        if (a == cows[0][i] || b == cows[0][i]){
            firstCow = cows[0][i];
            break;
        }
    }

    //Now we check each row and see if the first cow is correct
    for (int row = 1; row < k; row++){
        for (int col = 0; col < n; col++){

            //If we encounter one of the 2 cows
            if (cows[row][col] == a || cows[row][col] == b){
                //The first one is either correct
                if (cows[row][col] == firstCow)
                    break;
                //or not
                else
                    return false;
            }
        }
    }
    return true;
}
int main() {

    cin >> k >> n;

    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            cin >> cows[i][j];
        }
    }

    for (int i = 1; i <= n - 1; i++){
        for (int j = i + 1; j <= n; j++){
            //each combination here
         if (consistent(i, j))
            c++;
        }
    }

    cout << c;
}