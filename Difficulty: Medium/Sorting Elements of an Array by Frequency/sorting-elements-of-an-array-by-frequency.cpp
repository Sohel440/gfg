//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int, int> mp;
        for(auto tt : arr){
            mp[tt]++;
        }
        
        vector< pair<int,int> >v;
        for(auto tt: mp){
            v.push_back({tt.second , tt.first});
        }
        
        auto com =[&](auto i , auto j){
            if(i.first < j.first){
               return i.first > j.first;
            }else if(i.first == j.first){
                return i.second < j.second;
            }
        };
        
        sort(begin(v), end(v) ,com);
        vector<int> ans;
        
        for(auto tt: v){
            int no= tt.first ;
            while(no--){
                ans.push_back(tt.second);
            }
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends