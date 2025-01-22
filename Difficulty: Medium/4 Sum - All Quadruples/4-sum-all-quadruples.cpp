//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // arr[] : int input array of integers
    // target : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        // Your code goes here
        sort(begin(arr),end(arr));
        vector<vector<int>> ans;
        set<vector<int>> st;
        
        
        for(int i= 0 ; i < arr.size(); i++){
            
            for(int j = i +1 ; j < arr.size(); j++){
                
                int s = j+1;
                int e = arr.size()-1;
                
                int sum =0;
                
                while(s < e){
                    
                   // cout << arr[i] << " "<< arr[j] << " "<<  arr[s] << " "<< arr[e]<< endl;
                    
                    sum = arr[i] + arr[j] + arr[s] + arr[e];
                    if(sum > target){
                        e--;
                        
                    }else if(sum==target){
                        
                        if(!st.count({arr[i], arr[j], arr[s], arr[e]})){
                        ans.push_back({arr[i], arr[j], arr[s], arr[e]});
                        st.insert({arr[i], arr[j], arr[s], arr[e]});
                       
                        }
                         s++;
                        
                    }else{
                        s++;
                    }
                }
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(arr, d);
        sort(ans.begin(), ans.end());
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << endl;
        }
        if (ans.empty()) {
            cout << -1 << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends