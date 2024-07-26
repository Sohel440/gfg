//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[501][501];
    int solve(int i , int j , string &s , string &s1){
        
        if(i >= s.size() || j >= s.size()){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        
        if(s[i] == s1[j]){
            return dp[i][j] = 1+ solve(i + 1 , j+1 , s, s1);
            
        }
        
        return dp[i][j] = max(solve(i+1 , j , s, s1), solve(i, j+1 , s ,s1));
        
    }
    int countMin(string s){
    //complete the function here
    memset(dp , -1 , sizeof(dp));
       string s1 = s;
       reverse(begin(s1), end(s1));
       return s.size() - solve(0 , 0 , s , s1);
       
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends