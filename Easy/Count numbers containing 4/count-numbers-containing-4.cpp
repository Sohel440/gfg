//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isfind(int n){
        string a = to_string(n);
        return a.find('4') != string::npos;
        
    }
    int countNumberswith4(int n) {
        // code here
        int cnt =0;
        for(int i = 4 ; i <= n ; i++){
            if(isfind(i)){
                cnt++;
            }
        }
        return cnt;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends