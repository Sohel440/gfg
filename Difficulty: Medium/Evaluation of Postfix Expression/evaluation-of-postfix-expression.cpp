//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        for(int i =0 ; i < arr.size(); i++){
            
            if(arr[i] == "/" || arr[i] == "+"|| arr[i]=="-"|| arr[i] == "*"){
                
                int a = st.top();
                st.pop();
                int b  = st.top();
                st.pop();
               // cout << a << " " << arr[i] << " " <<b << endl;
                int ans ;
                if(arr[i] == "/"){
                    ans = b/a;
                }else if(arr[i] == "+"){
                    ans = b+a;
                }else if(arr[i] == "-"){
                    ans = b-a;
                }else if(arr[i] == "*"){
                    ans = b *a;
                }
                
                st.push(ans);
            }else{
                
                st.push(stoi(arr[i]));
                
            }
        }
        
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends