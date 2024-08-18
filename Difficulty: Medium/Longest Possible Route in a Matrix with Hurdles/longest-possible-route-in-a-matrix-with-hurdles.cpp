//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
   // Check if position (a, b) is within bounds, is a '1', and not yet visited
bool ok(int a, int b, int n, int m, const vector<vector<int>> &mat, const vector<vector<int>> &vis) {
    return a >= 0 && b >= 0 && a < n && b < m && mat[a][b] == 1 && vis[a][b] == 0;
}

// Solve the longest path problem
int solve(int a, int b, int xd, int yd, const vector<vector<int>> &mat, vector<vector<int>> &vis) {
    // Check if reached destination
    if (a == xd && b == yd) {
        return 0;
    }
    
    // Check if out of bounds or invalid position
    if (a < 0 || b < 0 || a >= mat.size() || b >= mat[0].size() || mat[a][b] == 0) {
        return INT_MIN;
    }
    
    vis[a][b] = 1; // Mark current cell as visited
    
    int left = INT_MIN, right = INT_MIN, up = INT_MIN, down = INT_MIN;
    
    // Move left
    if (ok(a, b - 1, mat.size(), mat[0].size(), mat, vis)) 
        left = 1 + solve(a, b - 1, xd, yd, mat, vis);
    
    // Move right
    if (ok(a, b + 1, mat.size(), mat[0].size(), mat, vis)) 
        right = 1 + solve(a, b + 1, xd, yd, mat, vis);
    
    // Move up
    if (ok(a - 1, b, mat.size(), mat[0].size(), mat, vis)) 
        up = 1 + solve(a - 1, b, xd, yd, mat, vis);
    
    // Move down
    if (ok(a + 1, b, mat.size(), mat[0].size(), mat, vis)) 
        down = 1 + solve(a + 1, b, xd, yd, mat, vis);
    
    vis[a][b] = 0; // Unmark the current cell
    
    return max({left, right, up, down});
}

// Main function to find the longest path
int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    // Call solve function from the start point
    int result = solve(xs, ys, xd, yd, matrix, vis);
    
    // If no valid path is found, return -1 or some indication of impossibility
    return (result < 0) ? -1 : result;
}
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends