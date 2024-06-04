//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<vector<int>> ans;
	void solve(int i , vector<int> & arr , vector<int> &temp , int n){
	    
	   
	    if(n == 0){
	        ans.push_back(temp);
	        return;
	        
	    }
	     if(i >= arr.size()|| n < 0 ){
	        
	        return;
	        
	    }
	    
	    temp.push_back(arr[i]);
	    solve(i , arr , temp , n- arr[i]);
	    temp.pop_back();
	    solve(i + 1 , arr , temp , n );
	    
	}
	
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<int> temp , arr;
        for(int i = 1 ; i <= n ; i++){
            arr.push_back(i);
            
        }
        
        solve(0 , arr , temp , n);
        
        vector<vector<int>> res ;
        
        for(auto tt : ans){
            
           sort(rbegin(tt) , rend(tt));
           res.push_back(tt);
           
            
        }
        sort(begin(res), end(res));
        reverse(begin(res), end(res));
        
        return res;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends