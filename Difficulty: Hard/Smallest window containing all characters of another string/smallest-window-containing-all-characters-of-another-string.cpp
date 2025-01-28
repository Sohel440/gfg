//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s1, string &s2) {
        // Your code here
           int n = s1.size();
        
        unordered_map<char , int> mp;
        for(auto tt: s2){
            mp[tt]++;
        }
        
        int i = 0;
        int j =0;
        
        int ans =INT_MAX;;
        int count = s2.size();
        
        string str;
        while(j < n){
            
            if(mp[s1[j]] > 0){
                mp[s1[j]]--;
                count--;
            }else{
                mp[s1[j]]--;
            }
            
            while(count == 0){
                
                 if(ans > j-i+1){
                     str  = s1.substr(i , j-i+1);
                     ans = j-i+1;
                     
                 }
                 mp[s1[i]]++;
                if(mp[s1[i]] > 0){
                    count++;
                }
                i++;
                 
            }
            j++;
            
        }
        //cout << ans << endl;
        return str;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        Solution obj;
        string str = obj.smallestWindow(s1, s2);
        if (str.size() == 0) {
            cout << "\"\"" << endl;
        } else {
            cout << str << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends