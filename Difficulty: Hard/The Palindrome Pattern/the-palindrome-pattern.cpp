//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool isOk(vector<int>  &temp){
        
        int i =0;
        int j =temp.size()-1;
        
        while(i <= j){
            
            if(temp[i] != temp[j])
            {
                return false;
            }
            
            i++;
            j--;
            
        }
        
        return true;
        
    }
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        
        for(int i =0 ; i < n ; i++){
            vector<int>  temp;
            
            for(int  j = 0 ; j < n ; j++){
                
                int ch = arr[i][j] ;
                
                temp.push_back(ch);
                
            }
            
            if(isOk(temp)){
                //cout << temp<< endl;
            //       for(auto it : temp)cout << it ;
            // cout << endl;
                return  to_string(i) +" "+"R";
            }
           
        }
        
        
          for(int i =0 ; i < n ; i++){
            vector<int> temp;
            for(int  j = 0 ; j < n ; j++){
                
                int ch = arr[j][i] ;
                
                temp.push_back(ch);
                
            }
            
            if(isOk(temp)){
                return  to_string(i) +" "+"C";
            }
        }
        
        return "-1";
        
        
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends