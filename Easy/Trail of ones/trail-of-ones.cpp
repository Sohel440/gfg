//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public: 
     int mod = 1e9+7;
    int fun(int i, int n, int prev, int flag, vector<vector<vector<int>>> &dp) {
        if(i==n) {
            if(flag) return 1;
            return 0;
        }
        if(dp[i][prev][flag]!=-1) return dp[i][prev][flag];
        
        int pick=0, notpick=0;
        if(prev==0) {
            pick= fun(i+1, n, 1, flag, dp);
            notpick= fun(i+1, n, 0, flag, dp);
        }
        else {
            pick= fun(i+1, n, 1, 1, dp);
            notpick= fun(i+1, n, 0, flag, dp);
        }
        return dp[i][prev][flag]=(pick%mod + notpick%mod)%mod;
    }


    int numberOfConsecutiveOnes(int n) {
        if(n == 2) return 1;
       
        int prev =0;
        int curr = 1;
        int sum =1;
        
        for(int i = 3 ; i <= n ; i++){
            
            int newcurr = (curr + prev)%mod;
          
            prev = curr ;
            curr = newcurr;
              sum = ((sum * 2 )%mod + newcurr) %mod;
            
        }
        
        return sum ;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends