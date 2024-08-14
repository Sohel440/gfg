//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int mx =0;
    int dp[1001][1001];
    
    int solve(int i  , int j  , string &a , string &b){
        
        if(i >= a.size() || j >= b.size()){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans =0;
        
        if(a[i]== b[j]){
           
           ans =  1 + solve( i +1 , j+1 , a , b);
           mx = max(mx , ans);
          //return solve( i +1 , j+1 , a , b);
          
        }
        int take   = solve(i+1 , j, a , b);
        int nontake = solve(i , j+1 , a, b);
        
        
        return dp[i][j] = ans;
    }
    int longestCommonSubstr(string a, string b) {
        
        // your code here
        memset(dp , -1 , sizeof(dp));
        
         solve(0  , 0 , a , b);
         //cout << mx << endl;
         return mx;
         
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends