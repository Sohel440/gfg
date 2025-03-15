//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;

    int solve(int ind, vector<int> &coins, int sum) {
        if (sum == 0) return 0;
        if (sum < 0 || ind >= coins.size()) return 1e7; // Avoid unnecessary checks

        if (dp[ind][sum] != -1) return dp[ind][sum];

        int take = 1 + solve(ind, coins, sum - coins[ind]);
        int nontake = solve(ind + 1, coins, sum);

        return dp[ind][sum] = min(take, nontake);
    }

    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        dp.assign(n, vector<int>(sum + 1, -1)); // Dynamic memory allocation for efficiency
        int ans = solve(0, coins, sum);
        return (ans >= 1e7) ? -1 : ans; // Ensure valid output
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
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends