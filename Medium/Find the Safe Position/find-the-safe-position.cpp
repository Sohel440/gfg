//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int safePos(int n, int k) {
        // code here
        vector<int> ans;
        
       
       for(int  i = 1 ; i <= n ; i++){
           ans.push_back(i);
       }
       
       int ind =0;
       
       while(ans.size() > 1){
           
           ind = (ind+ k -1) %n;
           ans.erase(ans.begin()+ ind);
           n = ans.size();
           
       }
       
       
       return ans[0];
       
        
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends