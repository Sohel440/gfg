//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[205][10005];
    
    bool solve(int ind , vector<int> &arr , int sum){
        if(sum ==0){
            return true;
        }
        if(ind >= arr.size()){
            return sum ==0;
        }
        if(sum < 0 ) return false;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        
        bool take = solve(ind + 1 , arr  , sum - arr[ind]);
        bool nontake = solve(ind +1 , arr , sum);
        
        return dp[ind][sum] = take || nontake;
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        memset(dp , -1, sizeof(dp));
        
        return solve(0 , arr , sum);
        
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends