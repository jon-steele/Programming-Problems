//Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=858
#include <iostream>
#include <algorithm>
using namespace std;

//m busses
//c seats
int n, m, c;
int times[500000001];

bool possible(int wait){
    int bussesUsed = 0;
    int seatsUsed = 0;
    int cow = 0;
    int firstCowInBus = 0;

    //Placing each cow, i. 
    while (cow < n & bussesUsed <= m){
        seatsUsed = 0;
        firstCowInBus = cow;
        bussesUsed++;
        seatsUsed++;
        cow++;

        //For each bus, I iterate through each seat.
        while (seatsUsed < c){
            //If the next cow is going to push the wait time to be too late, we break, moving to next bus
            if (times[cow] - times[firstCowInBus] > wait)
                break;
            seatsUsed++;
            cow++;
        }
    }

    return(bussesUsed <= m);

}

int main(){

    //Setup
    cin >> n >> m >> c;



    for (int i = 0; i < n; i++){
        cin >> times[i];
    }

    sort(times, times + n);

    //I am going to binary search to find the best waiting time.
    int floor = 0;
    int ceil = times[n-1] - times[0];
    int mid = 0;
    int mi = times[n-1];

    while (floor < ceil){
        mid = floor + ((ceil - floor) / 2);

        //If this middle time is possible, then we can try a smaller value;
        if (possible(mid)){
            mi = min(mid, mi);
            ceil = mid;
        }

        else {
            floor = mid + 1;
        }
    }

    cout << mi << endl;

}