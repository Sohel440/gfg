//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
   
    
 bool dfs(int src, int parent, vector<int> adj[], vector<bool> &vis) {
    vis[src] = true;
    
    for (auto &neighbor : adj[src]) {
        if (neighbor != parent && vis[neighbor]) {
            return true; // Cycle detected
        }
        if (!vis[neighbor] && dfs(neighbor, src, adj, vis)) {
            return true; // Cycle detected in recursive call
        }
    }
    
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    
    for (int i = 0; i < V; i++) {
        if (!vis[i] && dfs(i, -1, adj, vis)) {
            return true; // Cycle found starting from vertex i
        }
    }
    
    return false; // No cycle found in the graph
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends