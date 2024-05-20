//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include<bits/stdc++.h>
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> e, int n)
    {
        // Your code here
          int c=1;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({e[i],start[i]});
        }
        sort(begin(v), end(v));
       // sort(begin(e) , end(e));
        
        
        int i =0;
        int j = 1;
        
        int  cnt =1;
        
        while(i < n && j < n ){
            
            if(v[i]. first < v[j].second){
                i = j;
                cnt++;
                
            }
            
            
            j++;
            
            
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends