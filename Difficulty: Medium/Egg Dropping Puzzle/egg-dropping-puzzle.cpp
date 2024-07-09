//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    
    int solve(int n , int k){
        
        if(k == 1 || n== 1 || k ==0){
            return k;
        }
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int mn = INT_MAX;
        for(int x =  1 ; x <=k ; x++){
            
            //break egg;
            int bg = solve(n-1 , x-1);
            //not break
            // means lke binary search 
            int nbg = solve(n, k - x);
            
            // take worst case
            
            int ans = 1 + max(bg , nbg);
            
            mn = min(mn , ans);
            
            
            
        }
        
        return dp[n][k] = mn;
        
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        memset(dp  , -1 , sizeof(dp));
        
        return solve(n , k);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends