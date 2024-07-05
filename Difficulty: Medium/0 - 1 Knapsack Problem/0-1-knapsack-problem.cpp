//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>> dp ;
    int solve(int i , int w , int wt[], int val[], int n){
        
        if( i >= n){
            return 0;
            
        }
        
        if(dp[i][w] != -1) return dp[i][w];
        
        int take =0;
        if(wt[i] <= w){
            take = val[i] + solve(i+1 , w-wt[i] , wt ,val , n);
            
        }
        
        int nontake = solve(i+1 , w , wt , val , n);
        
        
        return dp[i][w] =max(take  , nontake);
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       dp.resize(n+3 , vector<int> (W+3, -1));
       
       return solve(0 , W, wt , val , n);
       
       
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends