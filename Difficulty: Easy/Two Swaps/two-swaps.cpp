//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        if(is_sorted(begin(arr), end(arr))){
            return true;
        }
        int k = 2;
        int ind =1;
        unordered_map<int,int>mp;
        for(int i = 0;i < arr.size();i++){
            mp[arr[i]] = i;
        }
        
        for(int i = 0 ; i < arr.size(); i++){
            if(k ==0) break;
            if(arr[i] != i+1){
                swap(arr[i] , arr[mp[i+1] ]);
                k--;
            }
        }
        
        if(is_sorted(begin(arr), end(arr)) && k ==0){
            return true;
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends