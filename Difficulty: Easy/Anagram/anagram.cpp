//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        
        vector<int> freq(26 ,0) , freq1(26,0);
        
        for(auto tt : s1){
            freq[tt-'a']++;
        }
        for(auto tt: s2){
            freq1[tt-'a']++;
        }
        
        for(int i= 0 ;i < 26 ; i++){
            if(freq[i] != freq1[i]){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends