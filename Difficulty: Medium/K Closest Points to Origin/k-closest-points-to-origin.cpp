//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    typedef pair<int , int>  P;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        priority_queue< P , vector<P> , greater<P> > pq;
        for(int i = 0 ; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            
            int ans  = x*x + y*y;
            pq.push({ans , i});
            
        }
        
        vector<vector<int>> ans;
        
        while(!pq.empty() && k--){
            auto tt= pq.top();
            pq.pop();
            
            ans.push_back(points[tt.second]);
            
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends