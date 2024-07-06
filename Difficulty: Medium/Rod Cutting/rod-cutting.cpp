//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    vector<vector<int>> dp;
    
    int solve(int i , int arr[] , int n){
        if(i >= n || n < 0){
            return 0;
            
        }
       if(dp[i][n] != -1) return dp[i][n];
        int take =0;
        
        take = arr[i] + solve(i , arr , n-(i+1));
        int nontake = solve(i+1 , arr , n);
        
        return dp[i][n]= max(take , nontake);
        
    }
    int cutRod(int price[], int n) {
        //code here
        dp.resize(n+1 , vector<int> (n+1 , -1));
        return solve(0 , price , n);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends