// https://cses.fi/problemset/task/1132
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

int n;

vector<int> tree[200001];
vector<int> path;
vector<int> longest_path;
bool seen[200001];

// Result will hold the max path length of each node
int result[200001];

// Process inputs will take inputs
void process_inputs(){
    int a, b;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}

// Find longest path will update longest_path to contain the longest path.
void find_longest_path(int node){

    path.push_back(node);
    seen[node] = 1;

    if (path.size() > longest_path.size())
        longest_path = path;

    for (int i = 0; i < tree[node].size(); i++){
        if (seen[tree[node][i]] == 0)
            find_longest_path(tree[node][i]);
    }

    path.pop_back();
    // DFS to longest
}

// Fill will populate results with the maximum path length for each node in the longest path
void fill_longest_path(){
    int length = longest_path.size();

    for (int i = 0; i < longest_path.size() / 2; i++)
        result[longest_path[i]] = length--;
    
    if (longest_path.size() % 2 == 0)
        length++;
    
    for (int i = longest_path.size() / 2; i < longest_path.size(); i++)
        result[longest_path[i]] = length++;
}

// Fill subtree takes an integer node, and will "colour" all neighbouring nodes if not already coloured, then recurse on them
void fill_subtree(int node){

    // For each neighbouring node
    for (int i = 0; i < tree[node].size(); i++)
    {
        // If the neighbour node is not already coloured, or if it is, but this length is greater
        if (result[tree[node][i]] == -1)
        {
            // We colour it, and recurse on it's subtree
            result[tree[node][i]] = result[node] + 1;
            fill_subtree(tree[node][i]);
        }
        // If the neighbour is already coloured, consider the max between the two
    }
}

int main()
{

    memset(seen, 0, sizeof(seen));
    memset(result, -1, sizeof(result));

    process_inputs();
    
    // Setting up to find the longest path
    find_longest_path(1); // Find the longest path from any given node
    int leaf = longest_path.back(); // the final leaf will be the furthest node away
    path.clear();
    longest_path.clear();
    memset(seen, 0, sizeof(seen));

    // Now we can find the actual longest path
    find_longest_path(leaf);
    fill_longest_path();

    // Once we have our tree prepared, and the longest path filled in, we simply
    // fill in each subtree of the longest path recursively.
    for (int i = 0; i < longest_path.size(); i++)
        fill_subtree(longest_path[i]);

    // Afterwards, we can print it
    for (int i = 1; i <= n; i++)
        cout << result[i] - 1 << " ";
    
    cout << endl;
    
    return 0;
}