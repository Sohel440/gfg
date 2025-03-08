//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isPali(string &s){
        int i =0;
        int j = s.size()-1;
        while(i < j){
            if(s[i] != s[j])return false;
            i++;
            j--;
            
        }
        return true;
        
    }
    string longestPalindrome(string &s) {
        // code here
        string ans;
        int n = s.size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i+ 1 ; j < n; j++){
                
               if(s[i] == s[j] && j-i+1 > ans.size()){
                string t = s.substr(i , j-i+1);
                // cout << t << endl;
                
                bool ok = isPali(t);
                if(ok)ans = t;//cout << ans << endl;
               }
            }
        }
        return ans;
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
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends