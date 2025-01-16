//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        
        int khor= accumulate(begin(cost), end(cost) ,0);
        int kamai =accumulate (begin(gas), end(gas), 0);
        
        if(khor > kamai )return -1;
        
        int res = 0;
        
        int tot =0;
        
        for(int i =0 ;i < cost.size(); i++){
            tot += gas[i] - cost[i];
            if(tot < 0){
                tot =0;
                res = i+1;
            }
            
        }
        return res;
        
    }
};


//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> gas, cost;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            gas.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            cost.push_back(number2);
        }
        Solution ob;
        int ans = ob.startStation(gas, cost);

        cout << ans;

        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends