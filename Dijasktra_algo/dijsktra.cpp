class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> res(V , INT_MAX);
        priority_queue<pair<int,int>  , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        res[S]=0;
        pq.push({0, S});
        
        while(!pq.empty()){
            
            auto it = pq.top();
            
            int dist = it.first;
            int Newnode= it.second;
            
            pq.pop();
            
            for(auto i : adj[Newnode]){
                int adjDist = i[1];
                int adjNode = i[0];
                
                
                if(dist +adjDist < res[adjNode]){
                    res[adjNode] = dist+adjDist;
                    
                    pq.push({ res[adjNode] , adjNode});
                    
                }
                
            }
        }
        return res;
        
        
        
    }
};
