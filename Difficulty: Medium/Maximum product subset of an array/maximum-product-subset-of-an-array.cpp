//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int  m = 1e9+7;
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
  if (arr.empty()) return 0;

     if (arr.empty()) return 0;

    int zeroCount = 0;
    int posCount = 0;
    int negCount = 0;
    long long int posProduct = 1;
    long long int negProduct = 1;
    int maxNeg = INT_MIN;
    bool hasPositive = false;
    
    for (int num : arr) {
        if (num > 0) {
            posProduct *= num;
            posProduct = posProduct %m;
            hasPositive = true;
            posCount++;
        } else if (num < 0) {
            negProduct *= num;
            negProduct = negProduct%m;
            maxNeg = max(maxNeg, num);
            negCount++;
        } else {
            zeroCount++;
        }
    }

    // If all numbers are zero, the maximum product is 0
    if (posCount == 0 && negCount == 0) return 0;

    // If there is an odd number of negative numbers, remove the smallest absolute value negative number
    if (negCount % 2 != 0) {
        negProduct /= maxNeg;
    }

    // If there are no positive numbers and no negative numbers, and there are zeros in the array
    if (posCount == 0 && negCount == 0 && zeroCount > 0) return 0;

    // If there are no positive numbers, we only consider negative numbers and zeros
    if (!hasPositive && negCount == 1 && zeroCount > 0) return 0;

    return (posProduct%m * negProduct%m)%m;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends