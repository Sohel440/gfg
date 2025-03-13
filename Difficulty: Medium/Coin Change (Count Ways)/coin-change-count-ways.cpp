//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int dp[1005][1009];
    
    int solve(int ind ,vector<int>& coins, int sum ){
         if(sum < 0) return 0;
        if(ind >= coins.size()){
            if(sum == 0) return 1;
            
            return 0;
        }
       
        
       
         if( dp[ind][sum]  != -1 ) return  dp[ind][sum] ;
        
        int take = solve(ind , coins , sum - coins[ind]);
        int nontake = solve(ind + 1, coins , sum );
        
        return dp[ind][sum]= take + nontake;
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        memset(dp ,-1 , sizeof(dp));
        return solve(0, coins  , sum);
        
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends