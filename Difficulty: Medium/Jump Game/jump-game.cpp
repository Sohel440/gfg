//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int dp[1000007];
   int solve(int ind, int a[], int N) {
    if(ind == N-1) {
        return 1; // Reached the last index
    }
    
    if(ind >= N || a[ind]==0){
        return 0;
    }
    if(dp[ind] != -1) return dp[ind];
    
    for(int i = 1; i <= a[ind]; i++) {
        if(solve(ind + i, a, N) == 1) {
            return dp[ind]= 1; // Memoize and return success
        }
    }

    return dp[ind] = 0; // No valid path found
}

int canReach(int A[], int N) {
    memset(dp , -1, sizeof(dp));
    return solve(0, A, N);
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends