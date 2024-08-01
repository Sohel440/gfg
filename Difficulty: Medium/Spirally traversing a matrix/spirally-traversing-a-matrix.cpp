//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    vector<int> ans;
    void solve(int i , int j , int n  , int m , vector<vector<int>> &mat){
        if (i >= n || j >= m) {
        return;
    }
        // Traverse from left to right
    // for (int col = j; col < m; ++col) {
    //     ans.push_back(mat[i][col]);
    // }
    int col = j;
    while(col < m ){
        ans.push_back(mat[i][col]);
        col++;
    }
    
    
    // Traverse from top to bottom
    // for (int row = i + 1; row < n; ++row) {
    //     ans.push_back(mat[row][m - 1]);
    // }
    
    int row = i+1;
    while( row < n){
        ans.push_back(mat[row][m-1]);
        row++;
    }
    
    
    // Traverse from right to left
    // if ((n - 1) != i) { // Avoid duplicate row
    //     for (int col = m - 2; col >= j; --col) {
    //         ans.push_back(mat[n - 1][col]);
    //     }
    // }
    
    if(n-1 != i){
        
        int col = m-2;
        while(col >=j){
            ans.push_back(mat[n-1][col]);
            col--;
            
        }
    }
    
    // Traverse from bottom to top
    // if ((m - 1) != j) { // Avoid duplicate column
    //     for (int row = n - 2; row > i; --row) {
    //         ans.push_back(mat[row][j]);
    //     }
    // }
    
    if(m-1 != j){
        int row = n-2;
        while(row > i){
            ans.push_back(mat[row][j]);
            row--;
            
        }
    }

        
        solve(i+ 1 , j+ 1 , n-1 , m-1 , mat);
        
        
        
        
        
    }
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int n = matrix.size();
        int m = matrix[0].size();
        
        
        solve(0 ,0, n,m, matrix);
        
        // for(auto tt : ans){
        //     cout << tt << " ";
        // }
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends