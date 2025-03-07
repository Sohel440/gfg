//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int dp[1005][1005];
    
    int solve(int i , int j , string &s){
        if(i== j){
            return 1;
        }
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int take =0,nontake =0;
        if(s[i] == s[j]){
            take = 2 + solve(i +1 , j-1 , s);
        }
        nontake = max(solve(i + 1 , j , s), solve(i  , j-1 ,s));
        
        return dp[i][j] = max(take ,nontake);
    }
     
    int longestPalinSubseq(string &s) {
        // code here
        memset(dp , -1 , sizeof(dp));
        return solve(0 ,s.size()-1, s);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends