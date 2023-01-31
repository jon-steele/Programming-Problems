//Problem: https://codeforces.com/problemset/problem/1593/A
#include <iostream>
using namespace std;

void print(int arr[][3], int n);

int main(){

    int n, a, b, c, areq, breq, creq;
    cin >> n;

    int results[n][3];

    for (int i = 0; i < n; i++){
        cin >> a >> b >> c;

        //Lets calculate the rquired votes for a first
        areq = min(a - b, a - c);
        if (areq < 1)
            results[i][0] = abs(areq) + 1;
        else
            results[i][0] = 0;

        breq = min(b - a, b - c);
        if (breq < 1)
            results[i][1] = abs(breq) + 1;
        else
            results[i][1] = 0;

        creq = min(c - b, c - a);
        if (creq < 1)
            results[i][2] = abs(creq) + 1;
        else
            results[i][2] = 0;

    }

    print(results, n);
}

void print(int arr[][3], int n){

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}