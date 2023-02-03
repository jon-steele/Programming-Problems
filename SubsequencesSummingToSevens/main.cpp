//http://www.usaco.org/index.php?page=viewproblem2&cpid=595
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<long long> summed_remainder;

int main(){

    long long sum = 0;
    long long element;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> element;
        sum += element;
        summed_remainder.push_back(sum % 7);
    }

    int maximum = 0;

    //Let's check the largest pair of 0's, 1's ... , 6's.
    for (int i = 0; i < 7; i++){
        int low = 0;
        int high = n - 1;
        for (int j = 0; j < n; j++){

            if (summed_remainder[low] != i)
                low++;
            if (summed_remainder[high] != i)
                high--;
            if (high < low)
                break;

            if (summed_remainder[low] == i && summed_remainder[high] == i)
                maximum = max(high - low, maximum);
        }
    }

    cout << maximum << endl;
}