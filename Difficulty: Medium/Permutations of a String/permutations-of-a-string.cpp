//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  set<string> st;
  
    void solve(int ind , string &s){
        if(ind >= s.size()){
            return ;
            
        }
        
        
        for(int i = ind ; i < s.size(); i++){
            swap(s[i] , s[ind]);
          //  cout << s<< " ";
            st.insert(s);
            
            solve(ind+1  , s);
            swap(s[i],s[ind]);
            
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        solve(0, s);
        vector<string> ans(st.begin(),st.end());
        // for(auto tt: st){
        //     cout << tt << " ";
        // }
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
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends