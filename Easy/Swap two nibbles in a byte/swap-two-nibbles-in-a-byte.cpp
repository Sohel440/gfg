//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        
        int a = (n & 0x0F) << 4; // last digit from the last
        int b = (n & 0xF0)  >> 4; // first digit from the first
        
       // int s= (1 << 2); cout << s << endl;
        return a+b;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends