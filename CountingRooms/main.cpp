// https://cses.fi/problemset/task/1192
#include<iostream>
using namespace std;

int n, m;

int neighbourX[4] = {0, 0, 1, -1};
int neighbourY[4] = {1, -1, 0, 0};

int visited[1001][1001];
char grid[1001][1001];

// Check makes it easy to see if we are still in the bounds of the grid/room
bool check (int x, int y) {
  if (y < 0) 
    return false;
  if (x < 0) 
    return false;
  if (y >= n) 
    return false;
  if (x >= m) 
    return false;
  if (grid[y][x] == '#') 
    return false;
  return true;
}

void dfs (int y, int x) {
  visited[y][x] = 1;
  // dfs each valid direction
  for (int i = 0 ; i < 4 ; i++) {
    int nextX = x + neighbourX[i];
    int nextY = y + neighbourY[i];

    // We check each direction. If it is valid, and not traversed, we can continue our search on it.
    if (check(nextX, nextY)) {
      if (!visited[nextY][nextX]) {
        dfs(nextY, nextX);
      }
    }
  }
}

int main() {
    
    int components = 0;
    cin >> n >> m;

    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        cin >> grid[i][j];
        visited[i][j] = 0;
      }
    }

    // We iterate through each tile
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        // If the tile is a floor, and we havent visited it yet, we know we have a new component. 
        if (grid[i][j] == '.' && !visited[i][j]) {
          dfs(i, j);
          components++;
        }
      }
    }
    cout << components << endl;
    return 0;
}