#include <bits/stdc++.h>

using namespace std;

#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);


void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> a(k, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[j][i];
        }
    } // n*k

    for (int j = 0; j < k; j++) {
        for (int i = 1; i < n; i++) {
            a[j][i] |= a[j][i - 1];
        }
    } // n*k
    // for (int i = 0; i < k; i++) {
    //     for (int j = 0; j < n; j++) {
    //        cout << a[i][j]<< " ";
    //     }
    //     cout << endl;
    // }
    while (q--) {
        int m;
        cin >> m;
        int lo = 0, hi = n - 1;
        while (m--) {
            int r, c;
            char o;
            cin >> r >> o >> c;
            r--;
            if (o == '<') {
                int i = lower_bound(a[r].begin(), a[r].end(), c) - a[r].begin(); //>=c //logn
                // cout <<"< "<< i << endl;
                hi = min(hi, i - 1);
            } else {
                int i = upper_bound(a[r].begin(), a[r].end(), c) - a[r].begin(); //>c //logn
                // cout << "> " << i << endl;

                lo = max(lo, i);
            }
            
        } // O(mlogn)
        
        if (lo > hi) {
            cout << "-1\n";
        } else
            cout << lo + 1 << '\n';

    } // O(sum of m * logn)
}

// tc -> O(n*k + sum(m)*logn)
// sc -> O(n*k)

int32_t main() {
    fastIO;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}