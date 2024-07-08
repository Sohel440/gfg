//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int ans = -1; // Initialize ans to an invalid index
    
    void solve(int s, int e, vector<int>& arr, int key) {
        if (s > e) {
            return;
        }
        
        int mid = s + (e - s) / 2;
        
        if (arr[mid] == key) {
            ans = mid; // Update ans when key is found
            return; // No need to search further
        }
        
        // Check if the left half is sorted
        if (arr[s] <= arr[mid]) {
            if (key >= arr[s] && key < arr[mid]) {
                solve(s, mid - 1, arr, key);
            } else {
                solve(mid + 1, e, arr, key);
            }
        } else { // Right half is sorted
            if (key > arr[mid] && key <= arr[e]) {
                solve(mid + 1, e, arr, key);
            } else {
                solve(s, mid - 1, arr, key);
            }
        }
    }
    
    int search(vector<int>& arr, int key) {
        solve(0, arr.size() - 1, arr, key);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends