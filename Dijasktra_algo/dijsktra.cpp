class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
   typedef long long ll;
    typedef pair<int, int> P;
    int D;vector<int> ans;
    const int LARGE_VALUE= 2e9;
    ll dijkstra(vector<vector<int>> &edges , int n , int src , int dest) {

       unordered_map<ll, vector<pair<ll, ll>>> adj; //u -> (v, wt)

        for(vector<int>& edge : edges) {
            if(edge[2] != -1) {
                int u  = edge[0];
                int v  = edge[1];
                int wt = edge[2];

                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<ll> result(n, INT_MAX); //result[i] = shortest path distance of src to ith node
        vector<bool> visited(n, false);

        result[src] = 0; //src to src distance is 0
        pq.push({0, src});

        while(!pq.empty()) {
            ll currDist = pq.top().first;
            ll currNode = pq.top().second;
            pq.pop();

            if(visited[currNode] == true) {
                continue;
            }
            visited[currNode] = true;

            for(auto&[nbr, wt] : adj[currNode]) {
                if(result[nbr] > currDist + wt) {
                    result[nbr] = currDist + wt;
                    pq.push({result[nbr], nbr});
                }
            }
        }

        return result[dest];
    }
};
