//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int dp[1005][205][3];
    
    int solve(int ind ,vector<int>& prices , int k , bool bs){
        
        if(ind >= prices.size()){
            if(k >=0 ) return  0;
            else return INT_MIN;
        }
        if(k == 0) return 0;
        if(dp[ind][k][bs] != -1) return dp[ind][k][bs];
        
        int take =0;
        int nontake =0;
        
        if(!bs) take = (-1)* prices[ind] + solve(ind + 1 , prices , k , !bs);
        else if(bs) take = prices[ind] + solve(ind + 1, prices , k-1 , !bs);
        
        nontake = solve(ind +1 , prices , k , bs);
        
        return dp[ind][k][bs]= max(take  , nontake);
        
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
        memset(dp , -1 , sizeof(dp));
        bool bs = false;
        return solve(0 , prices , k  , bs);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends