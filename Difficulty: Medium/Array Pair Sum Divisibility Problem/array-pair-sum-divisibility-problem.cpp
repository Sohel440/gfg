//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> &nums, int k) {
        // Code here.
        
        /*
            (a + b) % k = 0 should be
            a % k =r1 ,  b % k = r2;
            r1 + r1 = k it is always
            
            
            so 
            
            
            a % k = k - (b% k);
            
        */
        if(nums.size() % 2 == 1) return false;
        if(k == 1) return true;
        int cnt =0;
        
        unordered_map<int,int> mp;
        
        
        for(int i = 0 ; i  < nums.size(); i++){
            
           int r1 = nums[i] % k;
           int r2 = k - r1;
           
           if(mp.find(r2) != mp.end()){
               mp.erase(r2);
           }else if(r1 % 2 == 0 && mp.find(0) != mp.end()){
               mp.erase(0);
           }else{
               mp[r1]++;
           }
             
        }
       // cout << cnt << endl;
        return mp.size()==0;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        bool ans = obj.canPair(arr, k);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends