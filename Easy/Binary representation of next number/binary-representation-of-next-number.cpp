//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    long long int bi_to_int(string &s){
        
        long long int ans =0;
        int p=0;
        
        for(int  i = s.size()-1 ; i >=0 ; i--){
            if(s[i] == '1'){
                ans += pow(2 , p);
                
            }
            
            p++;
            
        }
        return ans;
        
    }
    string int_bi (int n){
        
        string a ="";
        while(n){
            
            int rem = n % 2;
            a += to_string(rem);
            n = n/2;
            
        }
        reverse(begin(a), end(a));
        
        return a;
        
    }
    string binaryNextNumber(string s) {
        // code here.
        // int nxt = bi_to_int(s)+1;
        // return int_bi(nxt);
        set<char> st(s.begin(), s.end());

    // If all characters are the same
    if (st.size() == 1) {
        // If all characters are '1', handle the overflow case
        if (s[0] == '1') {
            string ans(s.size(), '0'); // Create a string of '0's with the same length as 's'
            ans.push_back('1'); // Append '1' at the end
            reverse(ans.begin(), ans.end()); // Reverse to get the correct binary representation
            return ans;
        }
    }

    int n = s.size();
    // Traverse the binary string from right to left to find the next number
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            s[i] = '0'; // Set current bit to '0' if it is '1'
        } else {
            s[i] = '1'; // Set current bit to '1' if it is '0'
            break; // No further carry needed, break the loop
        }
    }

    // Remove leading zeros
    size_t firstOne = s.find_first_not_of('0');
    if (firstOne != string::npos) {
        return s.substr(firstOne);
    } else {
        return "0"; // If all bits are zero, return "0"
    }
        
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
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends