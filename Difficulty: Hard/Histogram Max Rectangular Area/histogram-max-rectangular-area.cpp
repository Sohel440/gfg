//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find largest rectangular area possible in a given histogram.
    vector<int> solve(vector<int> &arr ){
        int n = arr.size();
        
         stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
        
        
    }
    
     vector<int> solve1(vector<int> &arr ){
        int n = arr.size();
        
         stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i< arr.size(); i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
        
        
    }
    int getMaxArea(vector<int> &arr) {
        // Your code here
        vector<int> next = solve(arr);
       
       
        
        vector<int> prev = solve1(arr);
        
        
        
        
        int ans =0;
        for(int i =0 ; i < next.size(); i++){
            
            int height = arr[i];
            if(next[i] == -1){
                next[i]= arr.size();
            }
            int width = next[i]-prev[i]-1;
            
            ans = max(ans , height*width);
            
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
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends