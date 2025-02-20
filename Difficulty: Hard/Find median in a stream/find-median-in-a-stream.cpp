//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        // 5 15 1 3 2 8
        // 5 -> 5
        // 5 15 , 10
        // 5 15 1 -> 5
        // 1 3 5 15 -> (3+5)/2 -> 4.0
        // 1 2 3 5 15 -> 3
        // 1 2 3 5 8 15 -> (3 + 5)/2
        
        
        priority_queue<int > pq;
        priority_queue<int , vector<int> , greater<int> > mn;
        
        vector<double> ans;
        for(int i = 0 ; i < arr.size(); i++){
           
           if(pq.empty() || arr[i]<= pq.top()){
               pq.push(arr[i]);
           }else{
               mn.push(arr[i]);
           }
           
           if(pq.size() > mn.size()+1){
               auto it = pq.top();
               pq.pop();
               mn.push(it);
               
           }else if(pq.size()  < mn.size()){
               auto it = mn.top();
               mn.pop();
               pq.push(it);
           }
           
           if(pq.size()== mn.size()){
               ans.push_back((pq.top()+mn.top())/ 2.0);
           }else{
               ans.push_back(pq.top()* 1.0);
           }
        
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends