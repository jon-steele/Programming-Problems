// http://www.usaco.org/index.php?page=viewproblem2&cpid=895
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n;
int visited[1001][1001];
string line[1001];
int area, perimeter;
int bestArea, bestPerimeter = 0;

void dfs(int i, int j) {
    
    visited[i][j] = 1;
    area++;

    // Down
    if (i - 1 >= 0 && visited[i - 1][j] == 0 && line[i - 1][j] == '#')
        dfs(i - 1, j);
    else if (i - 1 < 0 || line[i - 1][j] == '.')
        perimeter++;

    // Up
    if (i + 1 <= n - 1 && visited[i + 1][j] == 0 && line[i + 1][j] == '#')
        dfs(i + 1, j);
    else if (i + 1 >= n || line[i + 1][j] == '.')
        perimeter++;

    // Left
    if (j - 1 >= 0 && visited[i][j - 1] == 0 && line[i][j - 1] == '#')
        dfs(i, j - 1);
    else if (j - 1 < 0 || line[i][j - 1] == '.')
        perimeter++;

    // Right
    if (j + 1 <= n - 1 && visited[i][j + 1] == 0 && line[i][j + 1] == '#')
        dfs(i, j + 1);
    else if (j + 1 >= n || line[i][j + 1] == '.')
        perimeter++;
}

int main()
{
    // Take input
    cin >> n;
    // memset(line, ' ', sizeof(line));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        cin >> line[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 0 && line[i][j] == '#') {
                area = 0;
                perimeter = 0;
                dfs(i, j);
                
                // Check if we have a better area
                if (bestArea < area){
                    bestArea = area;
                    bestPerimeter = perimeter;
                }
                // If areas are the same, and the perimeter is smaller, we choose the smaller perimeter.
                else if (bestArea == area && bestPerimeter > perimeter) {
                    bestPerimeter = perimeter;
                }
            }
        }
    }
    
    // Given the input, we want to find the largest 'blob' of '#' in the grid. Given the largest blob, we must output
    // the area, followed by a space, then the perimeter.

    cout << bestArea << " " << bestPerimeter << endl;

    return 0;
}