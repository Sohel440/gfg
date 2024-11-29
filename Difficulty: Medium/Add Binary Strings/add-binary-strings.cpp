//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        reverse(begin(s1), end(s1));
        reverse(begin(s2), end(s2));
        
        if(s1.size()<s2.size())swap(s1, s2);
        
        int i =0;
        int j =0;
        
        
        int carry =0;
        
        string ans;
        while(i<s1.size() && j < s2.size()){
            
            if((s1[i] == '1' && s2[j] == '0') ||(s1[i] == '0' && s2[j] == '1')){
                
                if(carry){
                    ans.push_back('0');
                }else{
                    ans.push_back('1');
                    
                }
            }else if(s1[i] == '1' && s2[j] == '1' ){
                
                if(carry){
                    ans.push_back('1');
                }else{
                    ans.push_back('0');
                }
                carry =1;
                
                
            }else if(s1[i] == '0' && s2[j] == '0'){
                if(carry){
                    ans.push_back('1');
                    carry =0;
                }else{
                    ans.push_back('0');
                    
                }
            }
            
            i++;
            j++;
            
        }
        
        
        while(i < s1.size()){
            
            if(s1[i]=='1'){
                if(carry){
                    ans.push_back('0');
                    
                }else{
                    ans.push_back('1');
                }
            }else{
                if(carry){
                    ans.push_back('1');
                    carry =0;
                    
                }else{
                    ans.push_back('0');
                    
                }
            }
            
            i++;
        }
        
        while(i < s2.size()){
            
            if(s2[j]=='1'){
                if(carry){
                    ans.push_back('0');
                    
                }else{
                    ans.push_back('1');
                }
            }else{
                if(carry){
                    ans.push_back('1');
                    carry =0;
                    
                }else{
                    ans.push_back('0');
                    
                }
            }
            
            j++;
        }
        if(carry)ans.push_back('1');
       
        
        reverse(begin(ans), end(ans));
         int ind =0;
        for(int i = 0 ;i < ans.size() ; i++){
            if(ans[i] != '0'){
                ind = i;
                break;
            }
        }
        
        string res = ans.substr(ind);
        
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends