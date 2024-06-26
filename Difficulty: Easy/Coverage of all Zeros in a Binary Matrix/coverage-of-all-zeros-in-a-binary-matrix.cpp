//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
   int n , m;
    bool isok(int i , int j){
        return i < n && j < m && j >= 0 && i >= 0;
        
    }
    
    int  cover(vector<vector<int>> &mat , int i  , int j ){
        
        int cnt =0;
        
       //left 
       if(isok(i, j-1)){
           if(mat[i][j-1] == 1)cnt++;
       }
       // right 
       
       if(isok(i , j + 1)){
           if(mat[i][j+1] == 1){
               cnt++;
           }
       }
       // top
       if(isok(i-1 , j)){
           if(mat[i-1][j] == 1) cnt++;
           
       }
       // bottom
       
       if(isok(i +1 , j)){
           if(mat[i+1][j] == 1) cnt++;
           
       }
       
       return cnt ;
       
        
    }
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int cnt =0;
        n = matrix.size();
        m = matrix[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j =0 ; j < m; j++){
                
                if(matrix[i][j] == 0){
                    cnt += cover(matrix , i , j);
                    
                }
                
            }
        }
        
        return cnt ;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends