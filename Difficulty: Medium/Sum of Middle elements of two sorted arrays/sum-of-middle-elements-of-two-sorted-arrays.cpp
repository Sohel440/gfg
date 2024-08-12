//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        vector<int> a;
        priority_queue<int, vector<int> , greater<int> > pq;
        
        for(auto it : arr1){
           pq.push(it);
        }
        for(auto it : arr2){
          pq.push(it);
        }
        while(!pq.empty()){
            a.push_back(pq.top());
            pq.pop();
            
        }
        // for (auto tt: a){
        //     cout << tt << " ";
        // }
        // cout << endl;
        
        int mid = a.size()/2;
        return a[mid-1]+ a[mid];
        
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends