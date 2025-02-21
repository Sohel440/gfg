//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> st;
        for(auto t:s){
            if(st.empty()){
                st.push(t);
                continue;
            }
            
            if(t == '{'||t == '('|| t == '['){
                st.push(t);
            }else{
                if(!st.empty() && st.top() == '(' && t == ')')st.pop();
                else if (!st.empty() && st.top() == '{' && t == '}')st.pop();
                else if(!st.empty() && st.top() == '[' && t == ']') st.pop();
                else st.push(t);
            }
        }
        
        return st.size() == 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends