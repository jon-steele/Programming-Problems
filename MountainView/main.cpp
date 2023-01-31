#include <iostream>
#include <algorithm>

using namespace std;

bool compare(long a[], long b[]){
    if (a[0] != b[0])
        return (a[0] < b[0]);
    else 
        return (a[1] > b[1]);
}

int main() {

    long n, x, y;
    cin >> n;
    long** peaks = new long*[n];
    for (long i = 0; i < n; i++) {
        peaks[i] = new long[2];
    }

    for (long i = 0; i < n; i++){
        cin >> x, cin >> y;
        peaks[i][0] = x - y;
        peaks[i][1] = x + y;
    }

    sort(peaks, peaks + n, compare);
    long nonvisible = 0;
    long i = 0;

    while (i < n){
        x = peaks[i][1];
        i++;

        while(i < n && peaks[i][1] <= x){
            nonvisible++;
            i++;
        }

    }

    cout << n - nonvisible << endl;
}