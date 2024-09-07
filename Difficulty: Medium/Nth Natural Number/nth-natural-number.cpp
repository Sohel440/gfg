//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        vector<int> a;
        long long p = 1;
        long long s =0;
        while(n ){
            
            int rem = n % 9;
            s += p * (rem);
            p = p * 10;
            
            n /= 9;
        }
       // reverse(begin(a), end(a));
        
        
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends