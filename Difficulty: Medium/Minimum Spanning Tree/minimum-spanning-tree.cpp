//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0 , {0 , -1}});
        int sum=0;
        vector<bool> vis(V , false);
        while(!q.empty()){
            
            int size = q.size();
            while(size--){
                auto it = q.top();
                q.pop();
                
                int w = it.first;
                int node= it.second.first;
                int par = it.second .second;
                	if (vis[node] == 1) continue;
                if(vis[node] != true){
                    sum += w;
                    vis[node] = true;
                }
                
                for(auto &v : adj[node]){
                    
                    int w = v[1];
                    int newNode=v[0];
                    
                    if(!vis[newNode]){
                        q.push({w , {newNode, node}});
                        
                    }
                }
                
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends