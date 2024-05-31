//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
          int n = 0;
    map<char, int> m;
    for (int i = 0; i < s.length(); i++) {
        m[s[i]]++;
    }
    for (auto a : m) {
        int p = a.first - 'a'+1;
        int f = a.second;
        if ((p % 2 == 0 && f % 2 == 0) || (p % 2 == 1 && f % 2 == 1)) {
        n++;
        }
    }
    if (n % 2 != 0)
        return "ODD";
    else
        return "EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends