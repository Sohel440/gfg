//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
     bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
    vector<int> getPrimes(int n) {
        // code here
        vector<int> a1;
        vector<vector<int>> p;
        for(int i =  2 ; i <n ; i++){
            
            int y = n-i;
            if(isPrime(i) && isPrime(y)){
                p.push_back({i , y});
                
            }
        }
        
        for(auto it : p){
            int a = it[0];
            int b = it[1];
            a1.clear();
            
            if(a < b){
                return {a, b};
            }else{
                a1.push_back(a);
                a1.push_back(b);
            }
        }
        if(a1.size() >0) return a1;
        return {-1 , -1};
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends