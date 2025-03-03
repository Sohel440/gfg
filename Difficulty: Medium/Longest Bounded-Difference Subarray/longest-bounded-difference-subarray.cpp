//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        
        int l =-1;
        int h =-1;
        
        int  i = 0;
        int j = 0;
        
        unordered_map<int,int> mp;
        set<int> st;
        
        
        int mx = 0;
        while(j < arr.size()){
            
            mp[arr[j]]++;
            st.insert(arr[j]);
            
            
            while( i < j && *st.rbegin() - *st.begin() > x){
                
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) {
                    mp.erase(mp[arr[i]]);
                    st.erase(arr[i]);
                }
                i++;
                
            }
            
            if(mx < j-i + 1 ){
                l= i;
                h = j;
                mx = j - i+1;
                
            }
            j++;
            
        }
        vector<int> ans;
        for(int i = l ; i <= h ;i++){
            ans.push_back(arr[i]);
            
        }
        // cout << l  << " "<< h << endl;
        return ans;
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends