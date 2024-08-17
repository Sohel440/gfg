//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        long long int mul =1;
        int ok = 0;
        for(auto tt : nums){
            if(tt == 0){
                ok++;
                continue;
                
            }
            mul = mul * tt;
        }
        
        vector<long long int> ans(nums.size(), 0);
        if(ok==0){
            
            for(int i = 0 ; i < nums.size(); i++){
                
                int val = nums[i];
                ans[i] = mul / val;
                
            }
            
        }
        
        
        if(ok > 1){
            return ans;
            
        }
        
        for(int i = 0 ;i < nums.size() ; i++){
            if(nums[i] == 0){
                ans[i]= mul;
            }
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends