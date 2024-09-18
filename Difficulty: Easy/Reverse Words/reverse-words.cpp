//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        int j =0;
        string temp;
        vector<string> ans;
        int i=0;
        for( i = 0 ; i < str.size() ; i++){
            
            if(str[i] == '.'){
                string t = str.substr(j , i-j);
                ans.push_back(t);
                j=i+1;
            }
        }
        
        ans.push_back(str.substr(j , i-j));
        reverse(begin(ans), end(ans));
        string a ="";
        for(int i = 0 ; i < ans.size(); i++){
            
            a+=ans[i];
            if(i != ans.size()-1)a +=".";
        }
        
        return a;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends