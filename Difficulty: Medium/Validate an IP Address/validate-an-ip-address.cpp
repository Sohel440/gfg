//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        vector<string> a;
        int i =0;
        string ans;
        
        for(int j = 0 ; j < str.size(); j++){
            if(( isalnum(str[j]) == false && str[j] != '.'))return false;
            if( j+ 1 < str.size() && str[j] == '.' && str[j+1] == '.')return false;
            
            if (str[j] == '.'){
                ans = (str.substr(i , j-i));
                a.push_back(ans);
                ans.clear();
                i = j+1;
            }
        }
       // if(!ans.empty()){
            
            a.push_back(str.substr(i , str.size()-i));
            if(a.size() != 4)return false;
            
            
        
        for(auto it : a){
             string temp =it;
             if(temp [0] == '0' && temp.size()> 1)return false;
             
            if(stoi(it) >255 || stoi(it) < 0){
                return false;
            }
        }
        return true;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends