
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;  // number of test cases
    std::cin >> t;

    while (t--) {
        int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    auto ans = (sum + x - 1) / x;
    int mx = *max_element(a.begin(), a.end());
    ans = max<int64_t>(ans, mx);
    cout << ans << '\n';
    }

    return 0;
}
