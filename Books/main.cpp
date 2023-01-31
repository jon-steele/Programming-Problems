//Problem: https://cses.fi/problemset/task/1631/
#include <iostream>
using namespace std;

int main(){

    int n;
    long current;
    cin >> n;

    //We must find the max int, and the sum of all other integers.
    //This is because if the longest book, x, takes longer than all 
    //the others, y, we must add  x - y time to our total time.

    long sum = 0;
    long mx = 0;

    for (int i = 0; i < n; i++){
        cin >> current;
        sum = sum + current;
        mx = max(mx, current);
    }

    //Now we have our sum, and our max.
    sum = sum - mx;

    if (n < 1)
        return 0;

    //If all our books besides max are less than the biggest book
    //Then both will have to wait while the other finishes the big book.
    //Time takes 2 times the biggest book.
    else if (sum < mx)
        cout << (2 * mx);
    
    //If our other books have more reading time than the max, then
    //They will be no waiting. This is because the person who reads the 
    //Biggest book will not hold up the other, and can simply move to one
    //of the smallest books once the biggest book has been read.
    else
        cout << (sum + mx);
}