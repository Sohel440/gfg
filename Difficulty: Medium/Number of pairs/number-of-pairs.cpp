//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   long long countPairs(vector<int>& arr, vector<int>& brr) {
     long long int count = 0;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for (int y : brr) {
        if (y == 1) cnt1++;
        else if (y == 2) cnt2++;
        else if (y == 3) cnt3++;
        else if (y == 4) cnt4++;
    }

    // Sort brr to allow binary search
    vector<int> sorted_brr = brr;
    sort(sorted_brr.begin(), sorted_brr.end());

    // For each x in arr, find the number of valid y in brr
    for (int x : arr) {
        if (x == 1) continue; // 1^y < y^1 for y > 1

        // Find the first index in sorted_brr where y > x using binary search
        auto it = upper_bound(sorted_brr.begin(), sorted_brr.end(), x);
        count += distance(it, sorted_brr.end()); // y > x

        // Add special cases:
        if (x == 2) {
            count += cnt1;       // 2^1 > 1^2
            count -= cnt3 + cnt4; // 2^3 < 3^2 and 2^4 < 4^2
        } else if (x == 3) {
            count += cnt1 + cnt2; // 3^1 > 1^3, 3^2 > 2^3
        } else {
            count += cnt1;        // x^1 > 1^x for x > 1
        }
    }

    return count;
}
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends