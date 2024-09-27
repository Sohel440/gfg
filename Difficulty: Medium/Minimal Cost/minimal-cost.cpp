//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[10001];
    int solve(int ind , int k , vector<int> &a){
        
        if(ind >= a.size()-1){
            return 0;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
            
        }
       int ans = 1e7;
        
        for(int i = ind + 1 ;i<=ind+k && i < a.size(); i++){
            
            int val = abs(a[ind]- a[i]) + solve(i   , k,a);
            ans = min(val , ans);
        }
        
        
        return dp[ind] = ans;
        
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        memset(dp , -1 , sizeof(dp));
        return solve(0 , k , arr);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends