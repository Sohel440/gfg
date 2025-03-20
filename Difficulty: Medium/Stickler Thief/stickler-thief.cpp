//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int dp[100005];
    
    int solve(int ind  , vector<int>&arr){
        if(ind >= arr.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int take  = arr[ind] + solve(ind + 2 , arr);
        int nontake = solve(ind +1 ,arr);
        
        return dp[ind] = max(take , nontake);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        memset(dp ,-1, sizeof(dp));
        
        return solve(0, arr);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends