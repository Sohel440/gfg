//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    
    
   
    int longestStringChain(vector<string>& words) {
        // Code here
             unordered_map<string, int> mp;
        
		//lambda function for sorting
        auto myFunction = [&](string& s1, string& s2) {
            return s1.length() < s2.length();
        };
        
        sort(begin(words), end(words), myFunction);  //O(N*logN)
        
        int maxChain = 0;
        for(string &word:words) { //O(N)
            int chain_word = 1;
            
            for(int i = 0; i < (int) word.length(); i++) {  // O(L)
                /*
					Find all possible predecessors of word by removing one character
					I you see that we have that predecessor, then we add +1 to the 
					predecessor chain to reach to current word.
					Similarly, for all possible predecessors, find the maximum chain to reach
					current word.
				*/
                string s = word.substr(0, i) + word.substr(i+1);  // O(L)
                auto it = mp.find(s);
            
                if(it != mp.end()) {
                    //find best predecessor
                    chain_word = max(chain_word, mp[s]+1);
                }
            }
            
            mp[word] = chain_word; //select the maximum chain for word
			//And at last find the maximum for all the words
            maxChain = max(maxChain, chain_word); //update the maximum chain obtained
        }
        
        return maxChain;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends