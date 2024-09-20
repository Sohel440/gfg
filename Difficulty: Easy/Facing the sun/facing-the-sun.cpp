//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        // code here
        vector<int> arr(height.size(), 0);
        arr[0] = height[0];
        for(int i = 0 ; i < height.size(); i++){
            
            arr[i] = max(height[i], arr[i-1]);
        }
        
        set<int> st;
        for(int i : arr){
            st.insert(i);
        }
        
        return st.size();
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> height;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            height.push_back(number);
        }
        Solution ob;
        int ans = ob.countBuildings(height);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends