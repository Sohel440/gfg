#include <iostream>
#include <vector>
#include <numeric> 
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int total_sum = accumulate(a.begin(), a.end(), 0);

    // If the total sum is not divisible by x, return the whole array length
    if (total_sum % x != 0) {
        cout << n << endl;
        return;
    }

    // Find the leftmost and rightmost elements that can be removed
    int left = -1, right = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] % x != 0) {
            left = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] % x != 0) {
            right = i;
            break;
        }
    }

    
    if (left == -1 && right == -1) {
        cout << -1 << endl;
        return;
    }

    
    int ans = max(n - left - 1, right);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
