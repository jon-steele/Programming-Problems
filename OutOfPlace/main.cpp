//http://www.usaco.org/index.php?page=viewproblem2&cpid=785
#include<iostream>
#include<vector>
using namespace std;

int heights[100];
vector<int> seen;
int n;

bool seenContains(int x){
    for (int i = 0; i < seen.size(); i++) {
        if (x == seen[i])
            return true;
    }
    return false;
}

int main()
{
    // Take inputs

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    // Find Bessie

    int bessie = 0;
    int bessieIndex = 0;

    if (n >= 3){
        for (int i = 1; i < n; i++) {
            if ((heights[i - 1] < heights[i] && heights[i] > heights[i + 1]) || (heights[i - 1] > heights[i] && heights[i] < heights[i + 1])) {
                bessie = heights[i];
                bessieIndex = i;
                break;
            }
        }
        // Find where Bessie belongs

        int bessieBelongs = 0;

        for (int i = 0; i < bessieIndex; i++) {
            if (bessie < heights[i]){
                bessieBelongs = i;
                break;
            }
        }

        // Count the number of unique elements from where bessie belongs, to where bessie is

        for (int i = bessieBelongs; i < bessieIndex; i++) {
            if (!seenContains(heights[i]))
                seen.push_back(heights[i]);
        }

        cout << seen.size() << endl;
    }
    else{
        cout << 1 << endl;
    }
}