//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  vector<string> ans;
    
    bool isok(int i, int j, vector<vector<int>> &mat) {
        return i >= 0 && j >= 0 && i < mat.size() && j < mat[0].size() && mat[i][j] == 1;
    }
    
    void solve(int i, int j, vector<vector<int>> &mat, string temp, vector<vector<int>> &vis) {
        int n = mat.size();
        
        // Base case: if we reach the bottom-right corner
        if (i == n - 1 && j == n - 1) {
            ans.push_back(temp);
            return;
        }
        
        vis[i][j] = 1;
        
        // Move left
        if (isok(i, j - 1, mat) && !vis[i][j - 1]) {
            solve(i, j - 1, mat, temp + "L", vis);
        }
        
        // Move right
        if (isok(i, j + 1, mat) && !vis[i][j + 1]) {
            solve(i, j + 1, mat, temp + "R", vis);
        }
        
        // Move down
        if (isok(i + 1, j, mat) && !vis[i + 1][j]) {
            solve(i + 1, j, mat, temp + "D", vis);
        }
        
        // Move up
        if (isok(i - 1, j, mat) && !vis[i - 1][j]) {
            solve(i - 1, j, mat, temp + "U", vis);
        }
        
        vis[i][j] = 0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        if (mat.empty() || mat[0][0] == 0 || mat[mat.size() - 1][mat.size() - 1] == 0)
            return {};
        
        string temp = "";
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(), 0));
        solve(0, 0, mat, temp, vis);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends