#include <iostream>
#include <cmath>
using namespace std;

int n;
int sum[100001];

//Check will return a 1 or 0 depending on whether or not the inputted solution
//works or not. 
bool check(double x){

    double localmin = sum[1] - x;

    for (int i = 2; i < n; i++){
        if (sum[n] - x * n + localmin <= sum[i] - x * (i))
            return true;
        localmin = min(localmin, sum[i] - x * i);
    }

return false;
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++){
        int c;
       cin >> c;
       sum[i] = sum[i - 1] + c;
    }

    double high = 10000;
    double low = 1;
    double mid;

    while (high - low > 0.00001){
        mid = (high + low) / 2;

        if (check(mid)){
            high = mid;
        }
        else {
            low = mid;
        }
    }

    printf("%.3lf", high);
}