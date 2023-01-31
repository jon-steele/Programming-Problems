//Problem: https://codeforces.com/contest/782/problem/B
#include <iostream>
#include <iomanip>
using namespace std;

double position[120000];
double speed[120000];
double minimum, maximum;
int n;

//Upper bound finds the absolute lowest possible point if all people travel downwards for the same amount of time
double upperBound(double time){
    double bound = 0;
    for (int i = n - 1; i >= 0; i--){
        bound = max(bound, (position[i] - (speed[i] * time)));
    }
    return bound;
}

//Lower bound finds the absolute highest possible point, if all people travel upwards for the same amount of time
double lowerBound(double time){
    double bound = 9999999999999999;
    for (int i = 0; i < n; i++){
        bound = min(bound, (position[i] + (speed[i] * time)));
    }
    return bound;
}

bool check(double time){
    double lower = lowerBound(time);
    double upper = upperBound(time);
    return (lower >= upper);
}

int main(){

    minimum = 9999999999;
    maximum = 0;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> position[i];
        maximum = max(maximum, position[i]);
        minimum = min(minimum, position[i]);
    }
    for (int i = 0; i < n; i++){
        cin >> speed[i];
    }

    //Here we will perform a binary search, using the check function to determine
    //If a given mid value works. 
    double high = 9999999999;
    double low = 0;
    double mid = (high + low) / 2;

    //We need a precision of 10 ^ -6 or better
    while (high - low > 0.000000001){
        mid = (high + low) / 2;

        if(mid == high || mid == low)
            break;

        if (check(mid))
            high = mid;

        else
            low = mid + 0.000000001;

    }

    cout << fixed << setprecision(12) << high << endl;

    return 0;
}

