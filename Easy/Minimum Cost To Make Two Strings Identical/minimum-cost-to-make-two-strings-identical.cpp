//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int dp[1001][1001];
    int solve(int i , int j , string &x , string &y , int costx , int costy){
        if(dp[i][j] != -1) return dp[i][j];
        if(i == x.size()){
            return (y.size()- j) * costy;
        }
        if(j == y.size()){
            return (x.size()- i ) * costx;
            
        }
        
        
        
        if(x[i] == y[j]){
            return dp[i][j] = solve(i+1 , j+1 , x ,y, costx , costy);
        }
        
        int take = costx+ solve(i+1 , j ,  x, y , costx, costy);
        int nontake =  costy+ solve(i , j+1 , x, y, costx , costy);
        
        return dp[i][j] = min(take , nontake);
        
    }
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        memset(dp , -1  , sizeof(dp));
        
        return solve(0 ,0, x, y,costX, costY);
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends