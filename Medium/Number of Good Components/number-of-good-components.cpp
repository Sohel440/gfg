//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    
    void dfs(  int src ,  unordered_map<int,vector<int>> &mp , vector<bool> &vis , vector<int> &t ){
        t.push_back(src);
        vis[src]=true;
        for(auto it : mp[src]){
            if(vis[it] == false){
                vis[it]=true;
                dfs(it , mp , vis , t);
                
            }
        }
        
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        
        unordered_map<int,vector<int>> mp;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
            
        }
        int ans =0;
        
    vector<bool> vis(v+1 , false);
        for(int i = 1 ; i <= v ; i++ ){
            
            
            if(!vis[i]){
                
                vector<int> t;
                dfs(i , mp , vis , t);
                
                bool f = false;
                for(int i =0 ; i < t.size(); i++){
                    if(mp[t[i]].size() < t.size()-1){
                        f = true;
                        break;
                    }
                }
                if(f==false) ans++;
            }
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends