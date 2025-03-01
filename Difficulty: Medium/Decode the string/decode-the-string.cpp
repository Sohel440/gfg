//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
    stack<string> st;  // Stack to store previous decoded strings
    stack<int> cnt;    // Stack to store repeat counts
    string curr = "";  // Current decoded string
    int i = 0;

    while (i < s.size()) {
        if (isdigit(s[i])) { 
            // Extract the number (count)
            int num = 0;
            while (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            cnt.push(num); // Push repeat count to stack
            i--; // Adjust since the loop already moved i forward
        } else if (s[i] == '[') {
           
            st.push(curr);
            curr = "";
        } else if (s[i] == ']') {
            // Construct the repeated substring
            string temp = curr;
            curr = st.top(); st.pop(); // Restore previous string
            int repeat = cnt.top(); cnt.pop(); // Get the repeat count
            
            while (repeat--) curr += temp; // Append repeated string
        } else {
            curr += s[i]; // Normal character, add to current string
        }
        i++;
    }

    return curr;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends