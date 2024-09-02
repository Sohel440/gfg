//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#define p pair<int,pair<int,int>>      //Defining the type
class Solution{
    public:
    vector<vector<int>> neighbours = {{1,0},{-1,0},{0,1},{0,-1}};
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> result(n,vector<int>(n,INT_MAX));     //Initializing the Result vector
        priority_queue<p,vector<p>,greater<p>> pq;               //Min Heap Declaration
        
        pq.push({grid[0][0],{0,0}});     //Pushed {Distance,{start_x,start_y}}
        result[0][0] = grid[0][0];        //Marked Initial index as start of grid
        
        while(!pq.empty()){
            int dist = pq.top().first;        //Current Minimum Distance to reach Current Index
            auto ind = pq.top().second;
            
            int x = ind.first;          //Current Index
            int y = ind.second;
            pq.pop();
            
            for(auto neig: neighbours){
                int new_x = x+neig[0];         //Exploring the Neighbour index
                int new_y = y+neig[1];
                
                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n &&            //Checking the Boundary condition(Explained in Video(Link above)
                    result[new_x][new_y] > dist+grid[new_x][new_y]){
                    
                    result[new_x][new_y] = dist+grid[new_x][new_y];            //Update our result
                    pq.push({dist+grid[new_x][new_y],{new_x,new_y}});         //Pushed in Min-Heap so as to explore this option further
                }
            }
        }
        return result[n-1][n-1];       //Finally Returning the last index of result where we have to reach(Right Bottom)
    }
};   //For Detail Dry Run Check Above Youtube Link :)

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends