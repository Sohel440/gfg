//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    
    void build(int arr[], vector<int> &seg , int s , int e , int i){
        
        if(s == e){
            seg[i] = arr[s];
            return;
            
        }
        
        int mid = s + (e -s)/2;
        build(arr , seg , s , mid, 2*i +1);
        build(arr , seg , mid+1 , e ,2*i+2);
        
        seg[i] = seg[2*i+1]+ seg[2*i+2];
    }
    
    int query(int s , int e , int l , int h  ,int i , vector<int> &seg){
           if(l >= s && h <= e){
            return seg[i];
            
        }
        if(l >e || h < s){
            return 0;
        }
        
     
        
      int mid = l + (h-l)/2;
        
        
        
        int left = query(s , e , l , mid , 2* i +1 , seg);
        int right = query(s , e , mid+1 , h ,2 * i + 2,  seg);
        
        
        return left+right;
    }
    
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        // code here
        vector<int> seg(4*n);
        build(arr , seg ,0 , n-1, 0);
        vector<int> ans;
        
        for(int  i =0  ; i < 2*q ; i+=2){
            
            int a = queries[i];
            int b = queries[i+1];
            
            int val = query( a-1, b-1 ,0 ,n-1, 0 , seg);
            
            ans.push_back(val);
            
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends