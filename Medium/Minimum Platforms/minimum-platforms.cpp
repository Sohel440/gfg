//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
   
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	/* 
    	   arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
           dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
           
        */
        
        sort(arr , arr+n);
        sort(dep , dep+n);
        
        int cnt = 1;
        int mx =0;
        
        int i =0 ; int j = 1;
        
        while(j < n){
            
            if(dep[i] < arr[j]){
                i++;
                
            }
           else if(dep[i] >= arr[j]){
                cnt++;
            }
            
            j++;
            
        }
        return cnt;
        
    	
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends