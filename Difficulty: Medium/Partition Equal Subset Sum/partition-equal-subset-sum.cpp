//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    vector<vector<int>> dp;
    
    
    bool solve(int  ind , vector<int>& arr , int sum , int target){
        if(ind >=arr.size()){
            return sum == target;
        }
        if(sum == target){
            return true;
        }
        if(sum < target) return false;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        bool take  = solve(ind + 1, arr , sum - arr[ind] , target);
        bool nontake = solve(ind + 1 , arr ,sum  , target);
        
        return dp[ind][sum]= take || nontake;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
       
        int sum =0;
        for(auto t: arr){
            sum += t;
        }
        
        dp.assign(arr.size()+2 , vector<int>(sum+5, -1));
        if(sum % 2 != 0) return false;
        return solve(0 , arr , sum , sum/2);
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
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends