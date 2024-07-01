//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    int N;
    bool isok(int i , int j , vector<vector<int>> &m , vector<vector<bool>> &vis){
        
     
        return i>=0 && j >=0 && i < m.size() && j < m.size() && m[i][j] == 1 && !vis[i][j];
        
    }
    void solve(int i, int j , vector<vector<int>> &m , string temp , vector<vector<bool>> &vis){
        
        if(i == N-1 && j ==N-1){
            
            ans.push_back(temp);
            return;
            
        }
        
       
        vis[i][j] = true;
        if(isok(i , j-1 , m , vis)){
            
            solve(i, j-1 ,  m , temp+'L', vis);
            // vis[i][j-1] = false;
            
        }
        
         if(isok(i , j+1 , m , vis)){
             // vis[i][j+1] = true;
            solve(i, j+1 ,  m , temp+'R', vis);
           //  vis[i][j+1] = false;
            
        }
         if(isok(i-1 , j , m , vis)){
              //vis[i-1][j] = true;
            solve(i-1, j ,  m , temp+'U', vis);
             //vis[i-1][j] = false;
            
        }
         if(isok(i +1 , j  , m , vis)){
             // vis[i+1][j] = true;
            solve(i+1, j ,  m , temp+'D', vis);
              //  vis[i+1][j] = false;
            
        }
        
      vis[i][j] = false;
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
         // Check if the starting or ending positions are blocked
    if (m[0][0] == 0 || m[n-1][n-1] == 0) {
        return ans;
    }
        string temp;
        N =n;
        vector<vector<bool>> vis(n , vector<bool>(n , false));
        solve(0 , 0 ,  m , temp ,vis);
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends