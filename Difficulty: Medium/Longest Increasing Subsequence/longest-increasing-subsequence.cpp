//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[1005][1005];
    
    int solve(int prev , int curr , vector<int> &arr){
        if(dp[prev+1] [curr] != -1) return dp[prev+1][curr];
        if(curr >= arr.size())return 0;
        
        int take =0;
      
        
        if(prev ==-1 || arr[prev] < arr[curr]){
            take = 1 + solve(curr , curr + 1 , arr);
        }
        
        int nontake = solve(prev , curr+1 , arr);
        return dp[prev+1][curr] =  max(take , nontake);
    }
    int lis(vector<int>& arr) {
        // code here
        memset(dp , -1, sizeof(dp));
        
        return solve(-1 , 0 , arr);
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends