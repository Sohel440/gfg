//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mx = -1;
    int solve(int i , int j , string &a , string &b){
        
        if(i >= a.size() || j >= b.size()){
            return 0;
        }
        int ans =0;
        
        if(a[i] == b[j]){
            ans++;
            mx = max(ans  , mx);
            return solve(i +1 , j +1 , a , b);
        }
        
        int take    = solve(i+1 , j , a  , b);
        int nontake = solve(i , j+1 , a , b);
        
        
        return mx;
        
    }
    int longestCommonSubstr(string a, string b) {
        // your code here
        
        int n = a.size();;
        int m = b.size();
        
        vector<vector<int>> dp (n+1, vector<int> (m+1 , 0));
        int mx =0;
        for(int i = 1 ; i <=n ; i++){
            for(int j = 1 ;j <= m ; j++){
                
                if(a[i-1]==b[j-1]){
                    dp[i][j]= 1+ dp[i-1][j-1];
                    mx = max(dp[i][j] , mx);
                }
                
            }
        }
        
        // for(int i =1 ; i<=n ; i++){
        //     for(int j= 1 ; j <=m ;j++){
        //         cout << dp[i][j]<< " ";
        //     }
        //     cout << endl;
        // }
        
        
        
        
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