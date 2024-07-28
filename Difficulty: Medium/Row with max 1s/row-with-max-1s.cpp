//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > arr) {
        // code here
        int mx = 0;
        int i =0;
        int ans =-1;
        for(auto it : arr){
            
            vector<int> v = it;
          
            int ub = upper_bound(begin(v), end(v), 0)-v.begin();
           // mx = max(mx , it.size()-ub);
           int a = it.size()-ub;
           if(mx < a){
               ans = i;
               mx = a;
           }
           
           i++;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends