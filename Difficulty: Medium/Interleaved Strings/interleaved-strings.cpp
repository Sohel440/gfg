//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int dp[101][101][201];
    bool solve(int i , int j , int  k  , string &a , string & b , string &c ){
        
        if(k >= c.size()){
            return true;
        }
        if( dp[i][j][k] != -1){
            return  dp[i][j][k];
        }
        
        if(a[i] == c[k] && solve(i +1 , j, k+ 1 , a, b ,c)){
            return dp[i][j][k] =   true;
        }
        if(b[j] == c[k] && solve(i , j+1 , k+1 , a, b , c )){
            return dp[i][j][k] = true;
            
        }
        
        return  dp[i][j][k]=  false;
        
    }
    bool isInterleave(string a, string b, string c) 
    {
        //Your code here return true;
        if(a.size() + b.size() != c.size())return false;
        memset(dp , -1 , sizeof(dp));
        
        return solve(0 ,0, 0, a, b , c);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends