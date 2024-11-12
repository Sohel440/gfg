//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        vector<pair<int,int> > p;
        for(auto tt: arr){
            p.push_back(make_pair(tt[0] , tt[1]));
        }
        
        auto it = [&](auto a , auto b){
            if(a.second < b.second){
                return true;
            }
            return false;
        };
        
        sort(begin(p), end(p) , it);
        
        for(int i = 1 ; i < p.size(); i++){
            
            if(p[i].first < p[i-1].second){
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends