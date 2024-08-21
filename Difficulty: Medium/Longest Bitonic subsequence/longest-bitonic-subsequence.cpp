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
   int LIS(int n, vector<int>& nums, vector<int>& lis) {
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    return *max_element(lis.begin(), lis.end());
}

int LDS(int n, vector<int>& nums, vector<int>& lds) {
    for (int i = n - 1; i >= 0; i--) {
        lds[i] = 1;
        for (int j = n - 1; j > i; j--) {
            if (nums[i] > nums[j] && lds[i] < lds[j] + 1) {
                lds[i] = lds[j] + 1;
            }
        }
    }
    return *max_element(lds.begin(), lds.end());
}

int LongestBitonicSequence(int n, vector<int>& nums) {
    if (n == 0) return 0;

    vector<int> lis(n, 0);
    vector<int> lds(n, 0);

    LIS(n, nums, lis);
    LDS(n, nums, lds);

    int max_len = 0;
    for (int i = 0; i < n; i++) {
        if(lis[i]>1 && lds[i]> 1)
        max_len = max(max_len, lis[i] + lds[i] - 1);
    }

    return max_len;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends