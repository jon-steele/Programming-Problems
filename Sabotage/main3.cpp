#include <iostream>
#include <cmath>
using namespace std;

double minimum;

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

void bestAverage(int i, int j, int *milkingMachines, int n){
    int low = i;
    int high = j;
    int mid = i + ((j - i) / 2);

    if (i == j){
        minimum = min(minimum, average(i, j, milkingMachines, n));
    }

    //If we have a better result on the left side than the right, we know the answer is on the right side
    else if (average(low, mid, milkingMachines, n) < average(mid + 1, high, milkingMachines, n)){
        minimum = min(minimum, average(low, mid, milkingMachines, n));
        bestAverage(low, mid, milkingMachines, n);
    }

    else {
        minimum = min(minimum, average(mid + 1, high, milkingMachines, n));
        bestAverage(mid + 1, high, milkingMachines, n);
    }
}

void bestMedianAverage(int i, int j, int *milkingMachines, int n){
    //There are 2 moves. 

    //Expand to the left
    if (i - 1 > 0 && average(i - 1, j, milkingMachines, n) <= average(i, j, milkingMachines, n)){
        minimum = min(minimum, average(i - 1, j, milkingMachines, n));
        bestMedianAverage(i - 1, j, milkingMachines, n);
    }

    //Expand to the right
    else if (j + 1 < n - 1 && average(i, j + 1, milkingMachines, n) <= average(i, j, milkingMachines, n)){
        minimum = min(minimum, average(i, j + 1, milkingMachines, n));
        bestMedianAverage(i, j + 1, milkingMachines, n);
    }

    //If those two moves do not yield better results, we can end the recursion. 
    else
        return;
}

int main() {

    minimum = 10000;
    int n;
    cin >> n;
    int milkingMachines[n];
    for (int i = 0; i < n; i++){
       cin >> milkingMachines[i];
    }

    bestAverage(1, n - 2, milkingMachines, n);
    //Now we only have the best average if the best i & j lay on either side of the median.
    //Now we must test if the best result that lay on the median is smaller than the current best.

    bestMedianAverage((n / 2), (n / 2), milkingMachines, n);

    //Afterwards, I will check if the optimal solution rests on the median.
    cout << round(minimum * 1000) / 1000 << endl;
}