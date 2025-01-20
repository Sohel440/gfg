//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string FirstNonRepeating(string &s) {
        // Code here
        string ans;
        
        unordered_map<char , int>mp;
        queue<char> q;
        
        for(auto tt: s){
            
            mp[tt]++;
            
            q.push(tt);
            
            
            while(!q.empty() && mp[q.front()] > 1){
                q.pop();
            }
            if(q.empty()){
                ans .push_back('#');
                
            }else{
                ans.push_back(q.front());
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends