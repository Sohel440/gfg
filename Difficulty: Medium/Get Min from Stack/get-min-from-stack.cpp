//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> a;
    set<int> st;
    unordered_map<int,int> mp;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        a.push_back(x);
         st.insert(x);
        mp[x]++;
        
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(a.size()>0){
            
           int val = a.back();
           mp[val]--;
           if(mp[val] == 0){
               mp.erase(val);
               st.erase(val);
               
           }
           a.pop_back();
           
        
        }
        
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(a.size())return a.back();
        return -1;
        
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(st.size()>0)  return  *st.begin();
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends