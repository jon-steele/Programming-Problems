#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int n, current;
    cin >> n;

    vector<int> integers;

    for (int i = 0; i < n; i++){
        cin >> current;
        integers.push_back(current);
    }

    sort(integers.begin(), integers.end());
    int count = 0, i = 0;

    while (i < n){
        current = integers[i];
        i++;
        while (!integers.empty() && integers[i] == current){
            i++;
        }
        count++;
    }

    cout << count;
}