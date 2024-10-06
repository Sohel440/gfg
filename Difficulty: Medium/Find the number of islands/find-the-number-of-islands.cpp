//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool ok(int i , int j , vector<vector<char>> &grid){
        return i >=0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j]=='1';
    }
    void dfs(int i , int j  , vector<vector<char>> &grid){
        
        grid[i][j] = '0';
        
        if(ok(i , j+1 , grid)) dfs(i , j+1 , grid);  // right
        
        if(ok(i , j-1 , grid)) dfs(i , j-1 , grid); //left
        
        if(ok(i+1 ,j , grid)) dfs(i+1 ,j , grid);//down
        
        if(ok(i-1 , j , grid)) dfs(i-1 , j , grid);//up
        
        if(ok(i+ 1 , j-1  , grid)) dfs(i+ 1 , j-1  , grid);
        
        if(ok(i+1 , j+1 , grid)) dfs(i+1 , j+1 , grid); // top corner 
        
        if(ok(i-1 , j+1 , grid)) dfs(i-1 , j+1 , grid); // 
        
        if(ok(i-1, j-1 , grid)) dfs(i-1, j-1 , grid); // bott left
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        int cnt =0;
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j <m ; j++){
                
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i  , j, grid);
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