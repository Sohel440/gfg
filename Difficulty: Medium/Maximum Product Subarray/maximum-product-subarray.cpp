//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        
        // if(arr.size()==1)
        int mx =1;
        int mn = 1;
        
        
        int ans =0;
        int temp =1;
        for(auto t: arr){
           // cout << t << " ";
            temp = temp *t;
        }
      //  cout << endl;
        
        for(int i= 0 ;i  <arr.size(); i++){
            
            if(arr[i]<0){
                
                int t = mx ;
                
                mx = max(1 , mn*arr[i]);
             //   cout << mx * arr[i]<< endl;
                mn = min(1 , t * arr[i]);
                ans = max(mx ,ans);
                // cout << mx << mn << endl;
             
                
                
            }else if(arr[i] == 0){
              
                mx =1,mn =1;
            
                
            }else{
                
                mx = mx*arr[i];
                mn = min(1 , mn * arr[i]);
                // cout << mn << " " <<mx << endl;
                ans = max(mx ,ans);
                
            }
        }
        return ans == 1 ? temp: ans;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends