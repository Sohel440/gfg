//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int dp[1001][1001];
	int solve(int i , int j , string &a , string &b){
	    
	    if (i >= a.size() && j >= b.size()) {
        return 0; // Both strings are processed, no operations needed.
    }
    
    if (i >= a.size()) {
        return b.size() - j; // If 'a' is exhausted, insert remaining characters of 'b'.
    }
    
    if (j >= b.size()) {
        return a.size() - i; // If 'b' is exhausted, delete remaining characters of 'a'.
    }
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if (a[i] == b[j]) {
        return solve(i + 1, j + 1, a, b); // If characters match, move to the next character.
    }
	    
	    int del = 1 + solve(i+ 1 , j  , a , b);
	    int ins =1 + solve(i , j+1, a , b);
	    
	    return dp[i][j]=  min(del , ins);
	    
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    memset(dp , -1 , sizeof(dp));
	    return solve(0 ,0, str1 , str2);
	    
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends