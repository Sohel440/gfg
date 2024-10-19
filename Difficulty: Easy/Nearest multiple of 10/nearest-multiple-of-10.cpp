//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string s) {
        // Complete the function
        
        bool ok = true;
        
        if(s[s.size()-1] - '0'  <= 5){
            s[s.size()-1] = '0';
            ok = false;
        }
        
        if(!ok){
            return s;
        }
        
        int rem = 10 - s[s.size()-1] - '0' ;
        int carry =1;
        
        s[s.size()-1] = '0';
        
        for(int i = s.size()-2 ; i >=0 ; i--){
            if(carry == 1){
                int tt = s[i]-'0'+1;
                
                if(tt >=10){
                    carry =1;
                }else  carry =0;
                
                s[i] = tt%10+ '0';
                
            }else break;
            
        }
        if(carry){
           s = "1" +s ;
        }
        return s;
}
        

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends