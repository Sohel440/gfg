//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    
    
int findClosest(int n, int k, int arr[]) {
    int lo = 0;
    int hi = n - 1;
    int ans = arr[0];
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if (abs(arr[mid] - k) < abs(ans - k) || (abs(arr[mid] - k) == abs(ans - k) && arr[mid] > ans)) {
            ans = arr[mid];
        }
        
        if (arr[mid] < k) {
            lo = mid + 1;
        } else if (arr[mid] > k) {
            hi = mid - 1;
        } else {
            return arr[mid]; // k is exactly present in the array
        }
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
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends