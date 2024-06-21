//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>
class Solution {
  public:
    string compareFrac(string str) {
       
        
      std::vector<std::string> ans;
    std::string a;
    
    for (char ch : str) {
        if (ch == '/' || ch == ',' || ch == ' ') {
            if (!a.empty()) {
                ans.push_back(a);
                a.clear();
            }
        } else {
            a.push_back(ch);
        }
    }
    
    if (!a.empty()) {
        ans.push_back(a);
    }
    
    std::vector<int> res;
    for (const auto& it : ans) {
        if (!it.empty()) {
            res.push_back(std::stoi(it));
        }
    }

    if (res.size() < 4) {
        throw std::invalid_argument("Input string must contain at least four numbers.");
    }

    double bal = static_cast<double>(res[0]) / res[1];
    double gud = static_cast<double>(res[2]) / res[3];

    std::string sohel;
    if (bal > gud) {
        sohel = std::to_string(res[0]) + "/" + std::to_string(res[1]);
    } else if(bal == gud) {
        return "equal";
        
    }else{
        sohel = std::to_string(res[2]) + "/" + std::to_string(res[3]);
    }
    
    return sohel;
       
        
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends