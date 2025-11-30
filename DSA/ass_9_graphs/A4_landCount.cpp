#include <bits/stdc++.h>
using namespace std;

void dfs(int r, int c, vector<vector<char>>& grid, int m, int n) {
    // boundary + water check
    if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0')
        return;

    grid[r][c] = '0'; // mark visited

    // explore all 4 directions
    dfs(r+1, c, grid, m, n);
    dfs(r-1, c, grid, m, n);
    dfs(r, c+1, grid, m, n);
    dfs(r, c-1, grid, m, n);
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;

    int n = grid[0].size();
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(i, j, grid, m, n);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0'},
        {'0','1','0'},
        {'1','0','1'}
    };

    cout << numIslands(grid);
}
