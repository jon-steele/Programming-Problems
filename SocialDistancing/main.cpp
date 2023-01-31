//Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=1038
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//n cows
//m grass patches
long long n, m;
long long** grass = new long long*[400000];

bool comparator(long long a[], long long b[]){
    return (a[0] < b[0]);
}

bool check(long long distance) {
    
    long long previousCow = -9999999999;
    int count = 0;

    //We iterate through every single grass patch
    for (int i = 0 ; i < m; i++) {
        
        //For each grass patch, we iterate through cows, iterating our count if there is space,
        //and updating the position of the last cow that we placed.
        
        //We need to be wary of whether or not the cow will make it to the first space of the next
        //patch, as it may of fallen short, inbetween patches.
        while (max(previousCow + distance, grass[i][0]) <= grass[i][1]) {
            
            previousCow = max(previousCow + distance, grass[i][0]);
            count++;

            //Check if we ran out of cows
            if (count >= n) 
                break;
        }

        if (count >= n) 
            break;

        //Once we can no longer place cows inside the patch, me move to the next patch
    }
 
    //If our total used cows is equal to the inputted cows, we know there was space for each one.
    return (count >= n);
}

int main(){
    
    cin >> n >> m;

	for (long long i = 0; i < m; i++) {
		grass[i] = new long long[2];
        cin >> grass[i][0] >> grass[i][1];
	}

    sort(grass, grass + m, comparator);

    //Now we can binary search for the best distance we can manage.

    long long ceil = 9999999999;
    long long floor = 1;
    long long mid = floor + ((ceil - floor) / 2);
    long long best = 0;

    while (floor <= ceil){
        mid = (ceil + floor) / 2;

        //If the middle distance works, perhaps we can go smaller. 
        if (check(mid)){
            best = max(best, mid);
            floor = mid + 1;
        }

        //If the middle distance doesnt work, we need to aim higher. 
        else{
            ceil = mid - 1;
        }

    }

    cout << best << endl;

}