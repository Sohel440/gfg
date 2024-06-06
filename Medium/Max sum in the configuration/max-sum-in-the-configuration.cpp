//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
      
        // Calculate the initial sum S_0
        long long S_0 = 0;
        long long sum_a = 0;
        for (int i = 0; i < n; ++i) {
            S_0 += 1LL* i * a[i];
            sum_a += a[i];
        }
        
        // Initialize the maximum sum with the initial sum
        long long max_sum = S_0;
        
        // Calculate the sum for other rotations and update the maximum sum
        long long current_sum = S_0;
        for (int i = 1; i < n; ++i) {
            current_sum =  current_sum + sum_a - 1LL *n * a[n-i];
            max_sum = std::max(max_sum, current_sum);
        }
        
        return max_sum;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends