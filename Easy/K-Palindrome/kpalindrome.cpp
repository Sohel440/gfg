//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
 
class Solution{
public:
   int solve(int i, int j, string &str, vector<vector<int>> &dp) {
    if (i >= j) return 0;
    
    if (dp[i][j] != -1) return dp[i][j];
    
    if (str[i] == str[j]) {
        dp[i][j] = solve(i + 1, j - 1, str, dp);
    } else {
        int ti = 1 + solve(i + 1, j, str, dp);
        int nti = 1 + solve(i, j - 1, str, dp);
        dp[i][j] = min(ti, nti);
    }
    
    return dp[i][j];
}
    int kPalindrome(string str, int n, int k)
    {
        // code here
        
         // int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, n - 1, str, dp) >k ? 0 : 1;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends