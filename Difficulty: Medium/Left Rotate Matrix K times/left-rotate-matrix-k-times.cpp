//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        
         k = k % mat[0].size();
         vector<vector<int>> bal;
         
         for(int i = 0 ; i < mat.size(); i++){
             vector<int> a;
             for(int j =  0 ; j < mat[0].size(); j++){
                 a.push_back(mat[i][j]);
             }
             
             rotate(a.begin(), a.begin()+k , a.end());
             
             bal.push_back(a);
             
         }
         
         return bal;
         
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends