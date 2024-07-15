//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        // If sum s is greater than the maximum possible sum with d digits
    if (s > 9 * d) return "-1";

    // Result string to store the digits of the smallest number
    string result(d, '0');
    
    // Initialize sum s
    s -= 1;

    // Start filling from the end to make sure we get the smallest number
    for (int i = d - 1; i > 0; --i) {
        if (s > 9) {
            result[i] = '9';
            s -= 9;
        } else {
            result[i] = s + '0';
            s = 0;
        }
    }

    // The first digit must be adjusted to ensure the number is not starting with zero
    result[0] = s + 1 + '0';

    return result;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends