//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
     void nxtSmallestelement(vector<int> &arr , vector<int> &nxt){
        
        stack<int>st;
        for(int i = 0 ;i < arr.size(); i++){
             while(!st.empty() && arr[st.top()] > arr[i]){
            nxt[st.top()] = i;
            st.pop();
        }
        st.push(i);
        }
    }
    
    
    void prevSmallestElement(vector<int> &arr , vector<int> &prv){
        
        stack<int>st;
        
        
        for(int i = arr.size()-1  ;i >=0; i--){
             while(!st.empty() && arr[st.top()] > arr[i]){
            prv[st.top()] = i;
            st.pop();
        }
        st.push(i);
        }
    }
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        vector<int> next (arr.size(), -1);
        vector<int> prev (arr.size(), -1);
        
        nxtSmallestelement(arr, next);
        prevSmallestElement(arr, prev);
        
        for(int i = 0 ; i < next.size();i++){
            next[i] = next[i] == -1 ? n : next[i];
        }
        
        vector<int> ans(n ,0);
        for(int i = 0 ;i < n ;i++){
            int sz = next[i] - prev[i]-1;
            
            ans[sz-1] = max(arr[i], ans[sz-1]);
        }
        // for(auto t: ans){
        //     cout << t << " ";
        // }
        
        // cout << endl;
        for(int i = n-2 ; i >= 0  ;i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends