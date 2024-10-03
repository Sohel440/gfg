//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int n = nums.size();
        map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }
        vector<int> ans;
        
        
        // if(mp.size() == nums.size()){
        //     return {-1};
        // }
        for(auto it: mp){
            
            if(it.second > n/3){
                ans.push_back(it.first);
            }
        }
        
        if( ans.size() ==0) return  {-1};
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends