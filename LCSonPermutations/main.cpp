// https://codeforces.com/gym/102951/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> first(n), second(n), index_mapping(n + 1);
    
    for (int i = 0; i < n; i++)
    {
        cin >> first[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> second[i];
        index_mapping[second[i]] = i;
    }
    
    // Create a new sequence using the indexes of elements from the second sequence
    vector<int> new_sequence(n);
    for (int i = 0; i < n; i++)
    {
        new_sequence[i] = index_mapping[first[i]];
    }
    
    // Use patience sorting to find the longest increasing subsequence
    vector<int> patience_table;
    for (int val : new_sequence)
    {
        auto it = lower_bound(patience_table.begin(), patience_table.end(), val);
        if (it == patience_table.end())
        {
            patience_table.push_back(val);
        }
        else
        {
            *it = val;
        }
    }

    cout << patience_table.size() << endl;
    
    return 0;
}
