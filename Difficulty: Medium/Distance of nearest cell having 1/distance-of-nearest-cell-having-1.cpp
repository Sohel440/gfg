//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> dir = {{0,1} ,{0 ,-1}, {1, 0}, {-1, 0}};
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        
        priority_queue< pair<int  , pair<int ,int> >   , vector<pair<int  , pair<int ,int> >  > , greater<pair<int  , pair<int ,int> >  >  >pq;
        vector<vector<int>> dis(grid.size(), vector<int> (grid[0].size(), INT_MAX));
        
        for(int i = 0; i< grid.size(); i++){
            for(int j =0 ; j < grid[0].size(); j++){
              if(grid[i][j] == 1)  pq.push({0 ,{i, j}});
            }
        }
        
        while(!pq.empty()){
            
            auto it = pq.top();
            pq.pop();
            
            int ds = it.first;
            int i = it.second.first;
            int j= it.second.second;
            
            for(auto tt : dir){
                
                int i_ = i+ tt[0];
                int j_ = j +tt[1];
                
                if(i_ >=0 && j_ >=0 && j_ < grid[0].size()&& i_ < grid.size() && grid[i_][j_] == 0){
                    
                    if(dis[i_][j_] > ds+1){
                        dis[i_][j_] = ds+1; 
                        pq.push({ds+1 , {i_, j_}});
                    }
                }
            }
        }
        
        for(int i = 0; i< grid.size(); i++){
            for(int j =0 ; j < grid[0].size(); j++){
              if(grid[i][j] == 1)  dis[i][j]=0;
            }
        }
        return dis;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends