//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int dp[501][501];
    int solve(int ind  ,vector<int> &cost , int w){
        if(ind >= cost.size() ||w < 0 ){
            return 1e8+10;
            
        }
        if(dp[ind][w] != -1) return dp[ind][w];
        
        
        if(w ==0){
            return 0;
        }
        
        int take=0;
        
        if(cost[ind] != -1){
            
            take = cost[ind] + solve(ind   , cost , w-(ind+1));
            
        }
        
        int nontake =  solve(ind+1  ,cost , w);
        
        return dp[ind][w] = min(take , nontake);
        
        
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        memset(dp , -1 , sizeof(dp));
        int ans = solve(0 , cost , w);
        
        return ans == 0 ? -1 : ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends