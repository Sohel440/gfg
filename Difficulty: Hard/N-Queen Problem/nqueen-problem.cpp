//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++



class Solution {
public:
    vector<vector<int>> ans;
    
    bool isok(int i, int j, int n, vector<vector<int>> &vis) {
        int row = i;
    int col = j;

    // Check this row on the left side
    while (col--) {
        
        if (vis[row][col]) {
            return false;
        }
    }

    row = i;
    col = j;

    // Check upper diagonal on the left side
    while (row-- && col--) {
        if (vis[row][col]) {
            return false;
        }
    }

    row = i;
    col = j;

    // Check lower diagonal on the left side
    while (col >= 0 && row <=n-1) {
        if (vis[row][col]) {
            return false;
        }
        col--;
        row++;
    }

    return true;
    }

    void solve(int j, int n, vector<vector<int>> &vis, vector<int> &temp) {
        if (j >= n) {
            ans.push_back(temp);
            return;
        }

        for (int k = 0; k < n; k++) {
            if (isok(k, j, n, vis)) {
                vis[k][j] = 1;
                temp.push_back(k + 1);

                solve(j + 1, n, vis, temp);

                vis[k][j] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<int> temp;
        solve(0, n, vis, temp);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends