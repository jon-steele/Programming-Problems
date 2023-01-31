/**
 * Problem: https://cses.fi/problemset/task/1142/ 
*/
#include <iostream>
using namespace std;

long bestSize(long * pointer, long size){
        
        long *p = pointer;
        long best = 0;
        long smallestBar = *p;

        for (int i = 0; i < size; i++){

            if(smallestBar > *p)
                smallestBar = *p;

            best = max(best, (i + 1) * smallestBar);
            p++;
        }


    return best;
}

int main() {

    int n;
    cin >> n;

    long boards[n];

    for (int i = 0; i < n; i++){
        cin >> boards[i];
    }

    long best = 0;
    long * p;

    for (int i = 0; i < n; i++){
        p = boards + i;
        best = max(best, bestSize(p, n - i));
    }

    cout << best;

}