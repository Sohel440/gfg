//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        unordered_map<int ,int >mp;
        set<int> st;
        
        int i =0;
        int j =0;
        vector<int> ans;
        
        while(j < arr.size()){
            
            mp[arr[j]]++;
            st.insert(arr[j]);
            
            if(j-i+1 == k){
                
                ans.push_back(*st.rbegin());
                mp[arr[i]]--;
                if(mp[arr[i]] == 0){
                    mp.erase(arr[i]);
                    st.erase(arr[i]);
                }
                i++;
                
            }
            j++;
            
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends