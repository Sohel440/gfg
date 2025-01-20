//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        queue<int> q;
        vector<int> ans;
        
        int i =0;
        int j = 0;
        
        
        while(j < arr.size()){
            
            
            while(!q.empty() && j - k >= q.front()){
                q.pop();
            }
            
            if(arr[j] < 0 )q.push(j);
            
            if(j >= k-1){
                if(!q.empty())ans.push_back(arr[q.front()]);
                else ans.push_back(0);
                
            }
            
            j++;
            
        }
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
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends