//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    
    int solve (int prev , int curr , vector<int> &a){
        if(curr >= a.size())return 0;
        int take =0;
        if(abs(a[prev] - a[curr]) == 1 || prev == -1){
            take = 1 + solve(curr , curr+1 , a );
            
        }
        int nontake = solve(prev , curr+1 ,a);
        
        return max(take , nontake);
        
    }
    int longestSubseq(int n, vector<int> &a) {
        // code here
        return solve(-1 , 0 , a );
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends