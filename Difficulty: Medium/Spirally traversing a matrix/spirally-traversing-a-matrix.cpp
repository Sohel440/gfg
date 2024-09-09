//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  vector<int> ans;
    void solve(int i , int j ,int n  , int m , vector<vector<int> > &mat){
        if(i >=n || j >= m)return;
        
        int row = i;
        int col =j;
        
        while(col < m ){
            ans.push_back(mat[row][col]);
            col++;
        }
        col--;
        row++;
        if (row >= n) return;  // Check boundary condition
        
        while(row < n ){
            ans.push_back(mat[row][col]);
            row++;
        }
        row--;
        col--;
        if (col < j) return; 
        
        while(col >= j){
            ans.push_back(mat[row][col]);
            col--;
        }
        
        col++;
        row--;
         if (col >= m) return; 
         
        while(row > i ){
            ans.push_back(mat[row][col]);
            row--;
            
        }
         if (row < i) return; 
        
        
        solve(i+1 , j+1 , n-1 ,m-1 , mat);
        
        
    }
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int n = matrix.size();
        int m = matrix[0].size();
        
        solve(0  , 0, n , m ,matrix);
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