//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

#include <vector>
#include <algorithm>  // for std::max


class Solution {
public:
    std::vector<int> JobScheduling(Job arr[], int n) {
        // Assuming arr[] is passed as a pointer to an array of Jobs
        sort(arr , arr+n , [](Job a , Job b){
            return a.profit > b.profit;
        });
        
        int mx = 0;
        for(int i = 0; i < n; i++) {
            mx = std::max(mx, arr[i].dead);
        }
        
        std::vector<int> a(mx + 1, -1);
        
        for(int i = 0; i < n; i++) {
            int dea = arr[i].dead;
            int pr = arr[i].profit;
            // Schedule jobs within their deadlines
            for (int j = dea; j > 0; j--) {
                if (a[j] == -1) {
                    a[j] = pr;
                    break;
                }
            }
        }
        
        int totalProfit = 0;
        int cnt=0;
        
        for (int i = 1; i <= mx; i++) {
            if (a[i] != -1) {
                totalProfit += a[i];
                cnt++;
            }
        }
        
        return {cnt, totalProfit};  // Adjust return type as needed
    }
};


//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends