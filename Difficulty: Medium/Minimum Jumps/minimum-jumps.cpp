//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
  int minJumps(vector<int>& arr) {
    // Handle edge case where first element is 0
    if (arr[0] == 0 && arr.size() > 1) {
        return -1;
    }
    
    int ind = 0;
    int n = arr.size();
    vector<int> a;
    a.push_back(ind);
    
    while (ind < n - 1) {
        // If we can jump directly to or beyond the last index
        if (ind + arr[ind] >= n - 1) {
            a.push_back(n - 1);
            break;
        }
        
        int newn = ind + arr[ind];
        int newind = ind;
        int mx = -1;
        
        // Find the index with the farthest reachable position within the current jump range
        for (int i = ind + 1; i <= newn && i < n; ++i) {
            if (i + arr[i] > mx) {  // Maximizing the next reachable index
                mx = i + arr[i];
                newind = i;
            }
        }
        
        if (newind == ind) {
            return -1;  // If no further progress is possible, return -1
        }
        
        ind = newind;
        a.push_back(ind);
    }
    
    return a.size() - 1;  // The number of jumps taken is the size of the jump path minus 1
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends