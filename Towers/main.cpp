// https://cses.fi/problemset/task/1073
#include<iostream>
#include<vector>
using namespace std;

vector<int> towers;
int n;

// binary search through towers to find the best position
int search(int block){
    int high = towers.size() - 1;
    int low = 0;
    int mid = 0;

    while (high > low)
    {
        mid = (high + low) / 2;

        if (block < towers[mid] && block >= towers[mid - 1])
            return mid;
        else if (block < towers[mid])
            high = mid - 1;
        else if (block >= towers[mid])
            low = mid + 1;
                
    }

    if (high == low && block < towers[high])
        return high;
    else
        return -1;
}

int main()
{
    cin >> n;
    int blocks[n];
    for (int i = 0; i < n; i++)
    {
        cin >> blocks[i];
    }

    int pos = -1;

    for (int i = 0; i < n; i++)
    {
        //For each block, we can binary search for the minimum closest block.
        pos = search(blocks[i]);

        //If none is found, we add it to the vector of towers
        if (pos == -1)
            towers.push_back(blocks[i]);

        else{
            towers[pos] = blocks[i];
        }
    }
    
    cout << towers.size() << endl;

    return 0;
}