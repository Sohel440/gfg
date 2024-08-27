//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public: 
    /*You are required to complete this method */
    void solve(vector<int> &arr , vector<int> &ls){
        
        stack<int> st;
        for(int i =0 ; i < arr.size(); i++){
            if(i==0){
                ls[i]=0;
                st.push(arr[i]);
                continue;
            }
            
            
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                ls[i]= st.top();
                st.push(arr[i]);
                
            }else{
                
                ls[i]=0;
                st.push(arr[i]);
                
            }
            
            
        }
        
        
        // for(auto tt: ls){
        //     cout << tt << " ";
        // }
        // cout << endl;
    }
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        vector<int> ls(arr.size() , 0);
        solve(arr , ls);
        vector<int> narr = arr;
        reverse(begin(narr) , end(narr));
        vector<int> rs(narr.size(), 0);
        solve(narr , rs);
        reverse(begin(rs), end(rs));
        
        int mx =0;
        
        for(int i = 0 ; i < ls.size(); i++){
            mx = max(mx , abs(ls[i]- rs[i]));
        }
        
        return mx;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends