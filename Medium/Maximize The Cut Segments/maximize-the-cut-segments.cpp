//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int dp[10001];
    int solve(int n , int x , int y ,int z){
        if(n ==0) return 0;
        if(n < 0 ) return INT_MIN;
        if(dp[n] != -1) return dp[n];
        
        
        int nx  =1+ solve(n-x , x , y ,z);
        int ny = 1+solve(n- y , x, y , z);
        int nz = 1+solve(n -z , x, y,z);
        
        return dp[n] = max(max(nx , ny), nz);
        
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp , -1 , sizeof(dp));
        return solve(n , x , y, z) <= 0 ? 0 :  solve(n , x , y, z);
        
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends