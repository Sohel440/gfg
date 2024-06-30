//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
  bool boundary(int i, int j, vector<vector<char>>& mat) {
    return i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size() && mat[i][j] == '1';
}

void dfs(vector<vector<char>>& grid, int i, int j) {
    if (!boundary(i, j, grid)) return;

    // Mark the cell as visited
    grid[i][j] = '0';
    
    // Explore the neighboring cells
    if (boundary(i, j - 1, grid)) {
        dfs(grid, i, j - 1);
    }
    if (boundary(i, j + 1, grid)) {
        dfs(grid, i, j + 1);
    }
    if (boundary(i - 1, j, grid)) {
        dfs(grid, i - 1, j);
    }
    if (boundary(i + 1, j, grid)) {
        dfs(grid, i + 1, j);
    }
     if (boundary(i + 1, j+1, grid)) {
        dfs(grid, i + 1, j+1);
    }
     if (boundary(i - 1, j-1, grid)) {
        dfs(grid, i - 1, j-1);
    }
     if (boundary(i + 1, j-1, grid)) {
        dfs(grid, i + 1, j-1);
    }
     if (boundary(i -1 , j+1, grid)) {
        dfs(grid, i - 1, j+1);
    }
    
}

int numIslands(vector<vector<char>>& grid) {
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                cnt++;
                dfs(grid, i, j);
            }
        }
    }
    return cnt;
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends