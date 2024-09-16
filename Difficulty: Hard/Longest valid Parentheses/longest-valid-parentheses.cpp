//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // code here
        int open =0;
        int close =0;
        int ans =0;
        
        for(int i = 0 ; i <str.size(); i++){
            
            if(str[i] =='(')open++;
            else if(str[i] == ')')close++;
            
            if(close > open )open =0 , close =0;
            else if(open == close ) ans = max(ans , open + close);
            
            
        }
        int ans1=-1;
        close =0;
        open =0;
         for(int i = str.size()-1 ; i >=0; i--){
            
            if(str[i] =='(')open++;
            else if(str[i] == ')')close++;
            
            if(close < open )open =0 , close =0;
            else if(open == close ) ans1 = max(ans1 , open + close);
            
            
        }
        
        return max(ans , ans1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends