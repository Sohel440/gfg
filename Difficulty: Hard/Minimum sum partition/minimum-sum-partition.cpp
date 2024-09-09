//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  vector<vector<int>> dp;
    int solve(int i , int sum , int rs ,int n ,  int arr[]){
        
        if(i >= n){
            
            int s1 = sum;
            int s2 = rs -sum;
            
            return abs(s1 -s2);
            
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
            
        }
        int take = solve(i+1 ,sum+ arr[i] , rs ,n, arr);
        int nontake = solve(i +1 , sum , rs , n,arr);
        
        return dp[i][sum]= min(take  , nontake);
        
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    
	    int sum = accumulate(arr , arr+n ,0);
	    dp.resize(n , vector<int> (sum , -1));
	    return solve(0 , 0, sum ,n , arr);
	    

	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends