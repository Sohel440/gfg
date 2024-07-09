//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[501][501];

    bool palindrom(int i ,int j , string &str){
   
        
        while(i < j ){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
            
        }
        
        return true;
        
    }
    
    int solve(int i , int j , string &str){
        
        
        // explain the base case :
        // 1. when j and i out of bound it means that we calculate the whole partition
        // 2. when j is out of bound but still i is not exceed the bound then it means that their is no palindrom
        // so, return 1e9 because we need minimum number 
        
        
        if(j == str.size()){
        
           if(i < str.size()) return 1e9;
        else return 0;
            
        }
        
        
        if(dp[i][j]!= -1) return dp[i][j];
        
        
        int take = 1e9;
        int nontake = 1e9;
        
        if(palindrom(i , j , str)){
            take = 1 + solve(j+1 , j+1 , str);
            nontake = solve(i , j+ 1 , str);
            
        }
        else nontake = solve(i , j + 1 , str);
        
        return dp[i][j] =  min(take , nontake);
        
        
    }
    int palindromicPartition(string str)
    {
        // code here
        // why -1 ? beacause of the it count the parts
        // we know that if we  want to  partitioned the n part we need n -1 partition , and that my ans
        memset(dp , -1 , sizeof(dp));
        
        return solve(0 , 0 , str)-1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends