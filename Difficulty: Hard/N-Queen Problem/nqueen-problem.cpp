//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<vector<int>> ans;
    
    bool isok(int i ,int  j , vector<vector<int>> & b , vector<vector<bool>> &vis){
        
    int row = i;
    int col = j;

    // Check this row on the left side
    while (col--) {
        
        if (vis[row][col]) {
            return false;
        }
    }

    row = i;
    col = j;

    // Check upper diagonal on the left side
    while (row-- && col--) {
        if (vis[row][col]) {
            return false;
        }
    }

    row = i;
    col = j;

    // Check lower diagonal on the left side
    while (col >= 0 && row <= b.size()-1) {
        if (vis[row][col]) {
            return false;
        }
        col--;
        row++;
    }

    return true;
        
        
    }
    void solve( int j , int n ,vector<vector<int>>& b,vector<int> &temp , vector<vector<bool>> &vis){
        if(j >= n){
            
            ans.push_back(temp);
            return;
            
        }
        for(int k = 0 ; k < n ; k++){
            
            if(isok(k, j, b   , vis)){
                
            vis[k][j] = true;
            temp.push_back(k+1);
            
            solve(j+1 , n , b ,temp, vis);
            
            temp.pop_back();
            vis[k][j] = false;
            
        }
            
        }
        
        
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> b(n , vector<int> (n , 0));
        vector<vector<bool>> vis(n , vector<bool> (n , false));
        vector<int> temp;
        solve( 0 , n , b,temp ,  vis);
        set<vector<int>> st;
        for(auto it : ans){
            st.insert(it);
        }
        
        ans.clear();
        
        for(auto i : st){
            ans.push_back(i);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends