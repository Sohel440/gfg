//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        unordered_map<int, vector<int>> adj;
        for(auto it :edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> ans(N, 1e9);
        ans[src] = 0;
        
        while(!q.empty()){
            
            int sz = q.size();
            while(sz--){
                
                auto it = q.front();
                q.pop();
                int node = it.first;
                int dis = it.second;
                
                for(auto it : adj[node]){
                    
                    if(dis + 1 < ans[it]){
                        q.push({it, dis+1});
                        ans[it] = dis+1;
                    }
                }
                
                
            }
        }
        
        for(int i = 0 ; i < ans.size(); i++){
            if(ans[i] == 1e9)ans[i]=-1;
        }
        
       
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends