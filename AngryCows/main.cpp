//Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=594
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

long n, shots, c;
int haybales[50001];

//checks
bool possible(int r){

    int counter = 1;
    int lastShot = haybales[0];

    for (int i = 0; i < n; i++){
        if (haybales[i] > (2 * r) + lastShot){
            counter++;
            lastShot = haybales[i];
        }
    }
    return (counter <= shots);
}

int main() {
   
    //Setup
    cin >> n >> shots;
    
    for(int i = 0; i < n; i++){
        cin >> haybales[i];
    }

    sort(haybales, haybales + n);
    
    //Solution
    //Here I will binary search through the potential r values,
    //finding the smalles possible r.

    int floor = 0;
    int ceil = n;
    int mid;
    int m = haybales[n - 1];

    while(floor <= ceil){
        mid = floor + ((ceil - floor) / 2);

        //if this middle value is possible, we might be able to go smaller.
        if (possible(mid)){
            m = min(m, mid);
            ceil = mid - 1;
        }

        //if not possible, we need to search for larger values;
        else{
            floor = mid + 1;
        }
    }

    cout << m << endl;

}