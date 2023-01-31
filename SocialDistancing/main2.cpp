#include <iostream>
#include <algorithm>
using namespace std;

//n cows
//m grass patches
long long n, m;
long long** grass = new long long*[500005];

bool comparator(long long a[], long long b[]){
    return (a[0] < b[0]);
}

bool check(long long distance){
    long long cows = 1;
    long long lastCow = grass[0][0];
    long long patch = 0;

    // cout << "-------------" << endl;
    // cout << "Testing distance:" << distance << endl;

    // cout << "Put cow #0 in: " << grass[0][0] << endl;
    while (patch < m && cows < n){
        //If the next cow can go in this patch, we place him there then iterate
        if (grass[patch][1] >= lastCow + distance){
            // cout << lastCow + distance << " -> " << grass[patch][0] << ", " << grass[patch][1] << endl;
            
            //Either the cow can go here,
            if(grass[patch][0] > lastCow + distance){
                // cout << "put cow #" << cows << " in: "<< grass[patch][0] << endl;
                lastCow = grass[patch][0];
                cows++;
            }

            else {
                // cout << "Put cow #" << cows << " in: "<< lastCow + distance << endl;
                lastCow = lastCow + distance;
                cows++;
            }
        }

        //If he doest fit in the current patch, we need to iterate to the next patch.
        else{
            patch++;
        }
    }
    
    //If the number of cows we used is equivalent to n, we know this distance worked

    return (cows == n);
}

int main(){
    
    cin >> n >> m;

	for (long long i = 0; i < m; i++) {
		grass[i] = new long long[2];
        cin >> grass[i][0] >> grass[i][1];
	}

    sort(grass, grass + m, comparator);

    //Now we can binary search for the best distance we can manage.

    long long ceil = grass[m - 1][1] - grass[0][0] + 1;
    long long floor = grass[0][0] + 1;
    long long mid = floor + ((ceil - floor) / 2);
    long long best = 0;

    while (floor <= ceil){
        mid = floor + ((ceil - floor) / 2);

        // cout << "Attempting a distance of: " << mid << endl;

        //If the middle distance works, perhaps we can go smaller. 
        if (check(mid)){
            // cout << "Success" << endl;
            best = max(best, mid);
            floor = mid + 1;
        }

        //If the middle distance doesnt work, we need to aim higher. 
        else{
            // cout << "Fail" << endl;
            ceil = mid - 1;
        }

    }
    cout << best << endl;

}