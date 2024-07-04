//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      vector<vector<int>> dp;
    int mod = 1e9+7;

    int solve(int i, vector<int>& arr, int n, int sum) {
        if (i >= n) {
            return sum == 0 ? 1 : 0;
        }
        
        if (sum < 0) return 0;

        if (dp[i][sum] != -1) return dp[i][sum];

        int take = solve(i + 1, arr, n, sum - arr[i]) % mod;
        int nontake = solve(i + 1, arr, n, sum) % mod;

        return dp[i][sum] = (take + nontake) % mod;
    }

    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int k = sum - d;
        if (k < 0 || k % 2 == 1) {
            return 0;
        }
        
        dp.resize(n, vector<int>(k/2 + 1, -1));
        return solve(0, arr, n, k / 2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends