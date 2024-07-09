//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(begin(arr), end(arr));
        
        int ans = 0;
         int diff = INT_MAX;
        
        
        for(int i = 0 ; i < arr.size()-2; i++){
            
            int s = i+1;
            int e = arr.size()-1;
            
           
            
            while(s < e){
                
                int sum =0;
                
                sum += arr[i];
                sum += arr[s];
                sum += arr[e];
                
                //cout << sum << endl;
                int temp = abs(sum - target);
                
                  if (temp < diff || (temp == diff && sum > ans)) {
                diff = temp;
                ans = sum;
            }
                
                if(sum > target){
                    e--;
                }else{
                    s++;
                    
                }
            }
            
        }
        
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
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends