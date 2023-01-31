#include <iostream>
#include <iomanip>
using namespace std;

double position[120000];
double speed[120000];
double n, minimum, maximum;

//Returns true if the person, pi, can reach the location i, in x seconds
bool canReach(int pi, double x, double i){

    //If the person is above the desired meeting location
    if (position[pi] > i){
        return (position[pi] - (x * speed[pi]) <= i);
    }

    //If the person is beneath the desired meeting location
    else if (position[pi] < i) {
        return (position[pi] + (x * speed[pi]) >= i);
    }

    //If the person is on the meeting location
    else{
        return true;
    }
}

//x is the time we are checking
bool check(double x){

    bool allReach = true;
    //Given an array of positions, and an array of their given speeds,
    //Is it possible for n people to meet in under x time?

    //This loop will iterate through every possible meeting location
    for (double i = minimum; i <= maximum; i = i + 0.1){
        allReach = true;
        for (int pi = 0; pi < n; pi++){
            if (!canReach(pi, x, i)){
                allReach = false;
                break;
            }
        }
        if (allReach == true)
            return true;
    }

    return false;
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

    // n = 3;
    // position[0] = 7;
    // position[1] = 1;
    // position[2] = 3;
    // speed[0] = 1;
    // speed[1] = 2;
    // speed[2] = 1;

    // maximum = 7;
    // minimum = 3;

    //Here we will perform a binary search, using the check function to determine
    //If a given mid value works. 
    double high = maximum + 1;
    double low = minimum - 1;
    double mid = (high + low) / 2;

    //We need a precision of 10 ^ -6 or better
    while (high - low > 0.00000000000001){
        mid = (high + low) / 2;

        if (check(mid))
            high = mid;

        else
            low = mid + 0.00000000000001;

    }

    cout << fixed << setprecision(12) << high << endl;

    return 0;
}

