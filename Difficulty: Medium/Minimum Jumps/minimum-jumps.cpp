//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int dp[10005];
    int solve(int ind , vector<int> &arr){
        if(ind == arr.size()-1) return 0;
        if(ind >=arr.size()) return 1e7;
        
        if(dp[ind] != -1) return dp[ind];
        
        int ans = 1e7;
        
        for(int i = 1 ; i <= arr[ind] ; i++){
            ans = min(ans , 1 + solve(ind + i , arr));
        }
        return dp[ind] = ans;
    }
    int minJumps(vector<int>& arr) {
        // code here
        memset(dp ,-1, sizeof(dp));
        
        int ans = solve(0 , arr);
        if(ans == 1e7) return -1;
        return ans;
        
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends