//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& a, int n) {
        
        vector<int> ans(n, -1);
        set<int> st;
        st.insert(a.back());
        
        for(int i = n-2 ; i >=0 ; i--){
            
            auto it = st.upper_bound(a[i]);
            if(a[i] >= *st.rbegin()){
                ans[i]=-1;
            }else{
                ans[i] = (*it);
            }
            
            st.insert(a[i]);
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends