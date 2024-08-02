//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int dp[101][101];
    
    int solve(int  i, int  j , string &a , string &b){
        
        if(i >=0 && j < 0){
            return i+1;
        }
        
        if(i < 0 && j >= 0){
            return j + 1;
            
        }
        if(i <0 && j < 0){
            return 0;
            
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(a[i]==b[j]){
            return solve(i-1  , j-1 , a, b);
            
        }
     
        int replace = 1+ solve(i -1 , j-1 ,a , b );
        int dele = 1+ solve(i-1  , j , a , b);
        int ins  =1 + solve(i, j-1 , a , b);
        
        return dp[i][j]= min({replace , dele , ins});
        
    }
    int editDistance(string a, string b) {
        // Code here
        memset(dp , -1 , sizeof(dp));
        return solve(a.size()-1 , b.size()-1 , a , b);
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends