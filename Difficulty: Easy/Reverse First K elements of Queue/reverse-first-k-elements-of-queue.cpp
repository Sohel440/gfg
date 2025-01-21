//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        vector<int> a;
        while(!q.empty() && k--){
            a.push_back(q.front());
            q.pop();
        }
        
        reverse(begin(a), end(a));
        queue<int> temp;
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
            
        }
        
        queue<int> ans;
        for(auto t: a){
            ans.push(t);
        }
        
        while(!temp.empty()){
            ans.push(temp.front());
            temp.pop();
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends