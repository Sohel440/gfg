//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCycle(vector<int> adj[], int src , vector<bool> &vis , vector<bool> &curr){
        
        vis[src] = true;
        curr[src] = true;
        
        for(auto &v : adj[src]){
             if(curr[v] == true){
                return true;
                
            }
            if(!vis[v] && isCycle(adj , v , vis , curr)){
                return true;
            }
           
        }
        curr[src] = false;
        return false;
        
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<bool> vis(V, false);
        vector<bool> curr(V , false);
        
        for(int i = 0 ; i < V  ; i++){
            
            if(!vis[i] && isCycle(adj , i , vis , curr)){
                return true;
            }
            
            
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends