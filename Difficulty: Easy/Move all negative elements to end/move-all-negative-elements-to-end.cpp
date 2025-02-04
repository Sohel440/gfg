//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
    //     int  n = arr.size();
        
    //     int j = 0;
    // for (int i = 0; i < n; i++) {
    //     if (arr[i] < 0) {
    //         if (i != j)
    //             swap(arr[i], arr[j]);
    //         j++;
    //     }
        
    // }
    
    // vector<int> ans;
    // for(int i=0 ; i < arr.size(); i++){
    //     if(arr[i] > 0){
    //         ans.push_back(arr[i]);
    //     }
    // }
    // for(int i=0 ; i < arr.size(); i++){
    //     if(arr[i] < 0){
    //         ans.push_back(arr[i]);
    //     }
    // }
    
    // for(int i=0 ; i < arr.size(); i++){
    //     arr[i]= ans[i];
    // }
    
   // reverse(begin(arr), end(arr));
   
   
    vector<int>res;
        for(int i:arr){
            if(i>=0){
                res.push_back(i);
            }
        }
        for(int i:arr){
            if(i<0){
                res.push_back(i);
            }
        }
        arr=res;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        ob.segregateElements(nums);

        for (int x : nums)
            cout << x << " ";
        cout << "\n~\n";
    }
}
// } Driver Code Ends