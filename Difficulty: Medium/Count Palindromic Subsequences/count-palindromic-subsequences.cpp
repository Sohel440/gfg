//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    const int mod = 1e9+7;
    set<string> ans;
    void solve(int ind ,string &s , string &t){
        
        if(ind >= s.size()){
            if(t.size()>0){
                ans.insert(t);
            }
            return;
            
        }
        t.push_back(s[ind]);
        solve(ind+1 , s ,t);
        t.pop_back();
        solve(ind+1 , s , t);
        
    }
    
    bool isPal(string &s){
        
        int i =0;
        int j =s.size()-1;
        
        while(i < j){
            
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
            
        }
        
        return true;
        
    }
    long long int dp[1001][1001];
    
    long long int helper(int i ,int j , string &s){
        
        if(i > j){
            return 0;
            
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == j){
            return dp[i][j] = 1;
        }
        long long int take =0;
        long long int nontake =0;
        
        if(s[i] == s[j]){
           return  dp[i][j]=  (1+ helper(i +1 , j , s) + helper(i , j-1 , s)) %mod;
        }
        return  dp[i][j]= (helper(i+1 , j , s) +  helper(i , j-1 , s) - helper(i + 1 , j-1  ,s) +mod) %mod;
        //return dp[i][j] = (take + nontake) %mod;
        
    }
    
    long long int  countPS(string str)
    {
       //Your code here
       memset(dp , -1 ,sizeof(dp));
       
       return helper(0, str.size()-1  , str);
       
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends