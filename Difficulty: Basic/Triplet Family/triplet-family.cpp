//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        sort(begin(arr), end(arr));
        unordered_map<int,int>mp;
        for(int i = 0 ; i < arr.size() ; i++){
            mp[arr[i]] =i;
        }
        
        for(int i =0 ; i < arr.size(); i++){
            
            for(int j = i +1 ; j < arr.size(); j++){
                
                int val = arr[i]+arr[j];
                if(mp.count(val) && mp[val] > j){
                    return true;
                }
            }
        }
        
        return false;
        
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
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends