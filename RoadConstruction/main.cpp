// https://cses.fi/problemset/task/1675/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m;
int ds[100005]; // disjoint set, used to track groups of roads
pair<int, int> roads[200005];

// Search returns the root of the group of a node
int search(int node){
    
    if(ds[node] < 0)
       return node;
    
    ds[node] = search(ds[node]);
    
    return ds[node];
}

// Merge tries to merge two groups
bool merge(int node1, int node2){
    
    node1 = search(node1); 
    node2 = search(node2);
    
    if(node1 == node2)  
        return false;
    if(ds[node1] < ds[node2])   
        swap(node1, node2);
    
    ds[node2] += ds[node1];
    ds[node1] = node2;
    
    return true;
}

int main(){
    cin >> n >> m;
    int a, b;
 
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        roads[i] = (make_pair(a, b));
    }
 
    fill(ds+1, ds+n+1, -1);
    int largest = 1;

    for(int i = 0; i < m; i++){

        pair<int, int> edge = roads[i];
        
        // If we successfully merge the two groups, we can add their sum to our total
        if (merge(edge.first, edge.second)){
            n--;
            largest = max(largest, -ds[search(edge.first)]); 
        }
        cout << n << " " << largest << endl;
    }
}