//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        if(arr.size() == 1){
            return arr[0];
        }
        
        string a = arr[0];
        string b = arr[1];
        
        int i =0 ; ;
        int j = 0;
        
        while(i < a.size() && j < b.size()){
            
            if(a[i] != b[j]){
                break;
            }
            i++;
            j++;
            
        }
        
        
        string temp = a.substr(0 , i);
        
      //  cout << temp << endl;
        
        for(int i = 2 ; i < arr.size(); i++)
        {
            
            string curr = arr[i];
           // cout << curr << " "<< temp << endl;
            int s =0; int e =0;
            
              while(s < curr.size() && e < temp.size()){
            
            if(curr[s] != temp[e]){
                break;
            }
            s++;
            e++;
            
        }
        
        
        string ex = temp.substr(0 , e);
         temp = ex;
         //cout << temp << endl;
         
            
        }
         return temp .size()==0?"-1": temp;
         
    }
    
   
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends