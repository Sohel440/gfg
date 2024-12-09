//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> & a,
                                       vector<int> & nw) {
        // code here
        
      //  cout << nw[0]<< endl;
        vector<vector<int>> ans;

    int i = 0;
    // Add all intervals before the overlap
    while (i < a.size() && a[i][1] < nw[0]) {
        ans.push_back(a[i]);
        i++;
    }

    // Merge overlapping intervals
    while (i < a.size() && a[i][0] <= nw[1]) {
        nw[0] = min(nw[0], a[i][0]);
        nw[1] = max(nw[1], a[i][1]);
        i++;
    }

    // Add the merged interval
    ans.push_back(nw);

    // Add all intervals after the overlap
    while (i < a.size()) {
        ans.push_back(a[i]);
        i++;
    }

    return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends