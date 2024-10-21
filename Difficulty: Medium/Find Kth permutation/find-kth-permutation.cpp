//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    unordered_set<string> st;
    priority_queue<string , vector<string> , greater<string>> pq;
    
    int k;
    string solve(int ind , string &s){
        if(ind >=s.size())return "";
        
        for(int i = ind ; i< s.size(); i++){
            if(st.size() == k){
                break;
            }
            swap(s[i] , s[ind]);
            st.insert(s);
            solve(ind+1 , s);
            swap(s[i] , s[ind]);
        }
        return "";
    }
    string kthPermutation(int n, int K)
    {
        // code here
        string t ="";
        k=K;
        for(int i = 1 ; i <= n ;i++){
            t += to_string(i);
        }

        while(K!=1){
            next_permutation(begin(t), end(t));
            K--;
        }
        
        return t;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends