//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      long long int  mod = 1e9+7;
 
    long long int solve(int ind , int sum , int d , vector<int> &arr , int tsum , vector<vector<int>> &dp){
        
      if(ind>=arr.size()){
           return (2*sum-tsum == d);
        }
       
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        
        long long int op1 = solve(ind+1, sum+ arr[ind], d,  arr , tsum , dp);
        long long int op2 = solve(ind+1, sum, d, arr , tsum , dp);
        
        return dp[ind][sum]=  (op1+op2)%mod;
    }
    
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        long long int sum = accumulate(begin(arr), end(arr), 0);
        if(sum - d < 0 || (sum+d) % 2) return 0;
        vector<vector<int>> dp(n , vector<int> (sum+1 ,-1));
        
        return solve(0 , 0, d , arr , sum , dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends