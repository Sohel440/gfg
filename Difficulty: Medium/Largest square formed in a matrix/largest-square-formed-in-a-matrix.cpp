//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<vector<int>> dp;
  
    int solve(int   i, int j ,vector<vector<int>> &mat, int &maxi){
        
        
        if(i >= mat.size() || j >=mat[0].size()){
            return 0;
        }
        if(dp[i][j] !=-1) return dp[i][j];
        
        
        int right = solve(i , j+1 , mat, maxi);
        int dia = solve(i+1 , j+1 , mat , maxi);
        int up = solve(i+1  , j, mat, maxi);
        
        
        
        if(mat[i][j] == 1)
        {
            dp[i][j]  = 1 + min(right , min(up , dia));
            maxi = max(maxi ,dp[i][j]  );
            return dp[i][j] ;
            
        }else 
        {
            return 0;
        }
       
        
        
    }
    
    int bottom(int i , int j , vector<vector<int>> &mat , int &maxi){
         int n = mat.size();
         int m = mat[0].size();
         vector<vector<int>> dp(n +1, vector<int> (m +1,0));
         
         for( i = mat.size()-1 ; i >= 0 ; i--){
             for( j = mat[0].size()-1 ; j >=0 ; j--){
                 
                
                int right = dp[i][j+1];
                int dia = dp[i+1][j+1];
                int up =   dp[i+1][j];
                
                  if(mat[i][j] == 1){
                      
                    dp[i][j]  = 1 + min(right , min(up , dia));
                    maxi = max(maxi ,dp[i][j]);
                  }
            }
        }
        return dp[0][0];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
       // dp.resize(n , vector<int> (m ,-1));
        int maxi = 0;
         bottom(0 , 0 , mat , maxi);
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends