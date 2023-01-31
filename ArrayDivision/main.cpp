#include <iostream>
#include <cmath>
using namespace std;

long long n, k;
long long arr[400000];

bool check(long long x){

    long long ki = 0;
    long long ni = 0;
    long long sum = 0;

    //We iterate through each "subarray"
    while (ki < k){

        //Inside each "subarray," we iterate until the sum of adding the next number in is greater than our target, x
        while (sum + (arr[ni]) <= x){
            
            sum = sum + arr[ni];
            ni++;

            if (ni >= n)
                break;
        }
        
        //At that point, we reset, and "move" to the next subarray
        sum = 0;
        ki++;
    }

    //by the time we reach the end, either our ni will be less than n, or not.
    //If not, we know that this number didnt work, as we didnt get through all the numbers.
    return (ni >= n);
}

int main(){

    long long maximum = 0;
    //Setup
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        maximum = max(maximum, arr[i]);
    }

    //Now we can binary search for the best number
    long long high = maximum * n;
    long long low = 0;
    long long mid;

    while (high > low){
        mid = round((high + low) / 2);

        if (check(mid))
            high = mid;
        
        else
            low = mid + 1;
    }

    cout << high << endl;
}