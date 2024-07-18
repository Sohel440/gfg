//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   
//int dp[100005+5][100005+5][2]; // dp array size adjusted to avoid too large allocation

int helper(int prev, int curr, int d, vector<int>& arr) {
    if (curr >= arr.size()) return 0;
    
    // if (dp[prev][curr][d] != -1) return dp[prev][curr][d]; // return memoized result
    
    int z = 0, o = 0, nontake = 0;
    
    if (d == -1) {
       return   1 + helper(curr, curr + 1, arr[curr] < arr[curr + 1] ? 0 : 1, arr);
        // if (curr + 1 < arr.size()) {
        //     return dp[prev][curr][d] = 1 + helper(curr, curr + 1, arr[curr] < arr[curr + 1] ? 0 : 1, arr);
        // } else {
        //     return dp[prev][curr][d] = 1;
        // }
    }
    

        if (d == 0) {
            if (arr[prev] < arr[curr]) {
                z = 1 + helper(curr, curr + 1, !d, arr);
            } else {
                o = helper(prev, curr + 1, d, arr);
            }
        } else {
            if (arr[prev] > arr[curr]) {
                z = 1 + helper(curr, curr + 1, !d, arr);
            } else {
                o = helper(prev, curr + 1, d, arr);
            }
        }
        
       // nontake = helper(prev, curr + 1, d, arr);
    
    
   // return dp[prev][curr][d] = max({z, o, nontake});
    nontake = helper(prev, curr + 1, d, arr);
        return max({z, o, nontake});

}

int alternatingMaxLength(vector<int>& arr) {
  if (arr.empty()) return 0;
    
      int inc = 1;
        int dec = 1;
        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] > arr[i-1])
                inc = dec +1;
            else if(arr[i] < arr[i-1])
                dec = inc + 1;
        }
        return max(inc,dec);
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends