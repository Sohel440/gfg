//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 const int m = 1000000007;
    int Maximize(vector<int> &arr) {
        // Complete the function
        sort(begin(arr), end(arr));
        priority_queue<int , vector<int> , greater<int> > pq (arr.begin(), arr.end());
        
        int i =0 ;
        long long int sum =0;
        
        
        while(!pq.empty()){
            long long int a = pq.top();
            long long int ans = ((a * i)%m)%m;
            
            sum =(sum +  ans%m) %m;
            i++;
            pq.pop();
            
        }
        
        
        return sum %m;
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends