//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
         vector<int>res;
   
        map<int,int>mp;
        int b=0;
        for(int i=0;i<arr.size();i++){
           mp[arr[i]]++;
            
        }
   
        for(auto it:mp){
            if(it.second==2){
                b=it.first;
                break;
            }
        }
        int a=0;
        int cnt=1;
    
        for(auto it:mp){
            if(cnt!=it.first){
                a=cnt;
                break;
            }
            cnt++;
        }
        if(a==0)
          a=arr.size();
      res.push_back(b);
      res.push_back(a);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends