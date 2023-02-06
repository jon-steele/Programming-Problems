//http://www.usaco.org/index.php?page=viewproblem2&cpid=1063
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int> > coords;

int main() {

    int x, y;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> x >> y;
        coords.push_back(make_pair(x, y));
    }

    sort(coords.begin(), coords.end());

    // In sums, the first number indicates the # of points above n, and the second indicates the # below
    pair<int, int> sums[n][n];

    for (int i = 0; i < n; i++){
        sums[i][-1].first = 0;
        sums[i][-1].second = 0;
    }


    for (int i = 0; i < n; i++){
        int y = coords[i].second;

        //For each element that comes after i, we compare the y's.
        for (int j = 0; j < n; j++){
            if (coords[j].second > y){
                sums[i][j].first = sums[i][j - 1].first + 1;
                sums[i][j].second = sums[i][j - 1].second;
            }
            else if (coords[j].second < y){
                sums[i][j].first = sums[i][j - 1].first;
                sums[i][j].second = sums[i][j - 1].second + 1;
            }
            else {
                sums[i][j].first = sums[i][j - 1].first;
                sums[i][j].second = sums[i][j - 1].second;
            }
        }
    }

    long long count = 1;

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){

            // For each combination of 2 cows, there is at least 1 solution.
            count++;

            // Since we have summed the number of elements above and below each element, we can use this to calculate
            // the number of higher and lower elements in linear time. 

            // Higher is simply the min of the two higher sums
            // and Lower is the min of the two lower sums

            if (abs(i - j) > 1){
                int higheri = sums[i][j].first - sums[i][i].first;
                int higherj = sums[j][j].first - sums[j][i].first;
                int loweri = sums[i][j].second - sums[i][i].second;
                int lowerj = sums[j][j].second - sums[j][i].second;

                int higher = min(higheri, higherj);
                int lower = min(loweri, lowerj);

                count = (higher + lower) + (higher * lower) + count;
            }
        }
    }

    // Since we double counted every combo once, 
    cout << count << endl;
}