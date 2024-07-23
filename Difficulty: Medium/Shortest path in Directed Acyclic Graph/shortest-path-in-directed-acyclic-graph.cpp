//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            adj[u].push_back({v, w});
        }

        // Priority queue for Dijkstra's algorithm, storing pairs of (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});  // Assuming starting node is 0, change if necessary
        
        // Distance vector, initialized to a large value
        vector<int> ans(N, 1e9);
        ans[0] = 0;  // Assuming starting node is 0, change if necessary

        while (!q.empty()) {
            int dis = q.top().first;
            int node = q.top().second;
            q.pop();

            for (auto neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;

                if (dis + weight < ans[nextNode]) {
                    ans[nextNode] = dis + weight;
                    q.push({ans[nextNode], nextNode});
                }
            }
        }

        // Replace distances that are still set to 1e9 with -1
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 1e9) ans[i] = -1;
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends