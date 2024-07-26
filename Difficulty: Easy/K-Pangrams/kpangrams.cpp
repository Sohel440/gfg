//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        vector<int> a(26, 0);
        for(int i = 0 ; i < str.size(); i++){
            if(str[i] == ' ') continue;
            
            a[str[i]-'a']++;
        }
        int sum =0;
        int cnt =0;
        for(auto it : a){
           // cout << it << " ";
            if(it == 0){
                cnt++;
            }
            sum += it;
        }
       // cout << sum << " "<<cnt <<  endl;
        if(sum < 26){
            return false;
        }
        
        
        if(cnt > k){
            return false;
        }
        return true;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends