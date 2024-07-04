//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	vector<vector<int>> dp ;
	int mod = 1e9+7;
	int solve(int i  , int arr[] , int n  ,int sum ){
	    
	    if(i > n-1){
	        if(sum == 0){
	            return 1;
	        }
	        else
	        return 0;
	        
	    }
	    
	    if(sum < 0 ) return 0;
	    
	    if(dp[i][sum] != -1) return dp[i][sum];
	    
	   // sum += arr[i];
	    int take =( solve(i +1 , arr , n , sum- arr[i]))%mod;
	    take = take %mod;
	   // sum-= arr[i];
	   int nontake = ( solve(i +1 , arr , n , sum))%mod;
	   nontake = nontake %mod;
	    
	    
	    return dp[i][sum]= (take + nontake) %mod ;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
       // memset(dp , -1 , sizeof(dp));
       dp.resize(n+1 , vector<int>(sum+1 , -1));
        return solve(0 , arr , n  , sum);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends