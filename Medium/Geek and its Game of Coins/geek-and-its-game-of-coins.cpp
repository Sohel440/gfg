//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
 bool wins(int n, int x, int y, std::vector<int>& dp) {
    if (n == 0) {
        return false; // If no coins are left, the current player loses
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    // Try all possible moves and see if the opponent loses in any of them
    bool condition1 = (n-1 >= 0 && !wins(n-1, x, y, dp));
    bool condition2 = (n-x >= 0 && !wins(n-x, x, y, dp));
    bool condition3 = (n-y >= 0 && !wins(n-y, x, y, dp));

    dp[n] = condition1 || condition2 || condition3;
    return dp[n];
}

int findWinner(int n, int x, int y) {
    std::vector<int> dp(n + 1, -1);
    return wins(n, x, y, dp);
}
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends