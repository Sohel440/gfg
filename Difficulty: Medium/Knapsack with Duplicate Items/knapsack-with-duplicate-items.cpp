//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int n;
    int dp[1001][1001];
    
    int solve(int ind , int *val , int *wt , int mx){
        if(ind >= n){
            return 0;
            
        }
        
        if(dp[ind][mx] != -1 ) return dp[ind][mx];
        
        int take =0;
        
        if(mx >= wt[ind]){
            take = val[ind] + solve(ind , val , wt , mx - wt[ind]);
            
        }
        int nontake = solve(ind + 1 , val , wt , mx);
        
        return dp[ind][mx] = max(take , nontake );
        
    }

int knapSack(int N, int W, int val[], int wt[]) {
    // dp.assign(N+3, vector<int>(W + 3, -1));
    memset(dp , -1 , sizeof(dp));
    
    n = N;
    return solve(0 , val , wt , W);
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends