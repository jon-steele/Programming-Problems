#include <iostream>
#include <cmath>
using namespace std;

double average(int i, int j, int *milkingMachines, int n){

    int counter = 0;

    for (int k = 0; k < n; k++){
        if (k == i){
            k = j;
        }
        else{
            counter = counter + (milkingMachines[k]);
        }
    }

    double divisor = (n - (j - i + 1));

    return counter / divisor;
}

int main() {

    int n;
    cin >> n;
    int milkingMachines[n];
    for (int i = 0; i < n; i++){
       cin >> milkingMachines[i];
    }

    double best = 10000;

    for (int i = 1; i < (n - 1); i++){
        for (int j = i; j < (n - 1); j++){
            best = min(best, average(i, j, milkingMachines, n));
        }
    }

    cout << round(best * 1000) / 1000 << endl;
}
