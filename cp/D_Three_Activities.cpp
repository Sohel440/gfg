#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<ll> p(n), q(n), r(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    vector<pair<ll, int>> a, b, c;

    for (int i = 0; i < n; i++) {
        a.push_back({p[i], i});
        b.push_back({q[i], i});
        c.push_back({r[i], i});
    }

    sort(a.begin(), a.end(), greater<pair<ll, int>>());
    sort(b.begin(), b.end(), greater<pair<ll, int>>());
    sort(c.begin(), c.end(), greater<pair<ll, int>>());

    ll mx = LLONG_MIN;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (a[i].second != b[j].second && b[j].second != c[k].second && a[i].second != c[k].second) {
                    mx = max(mx, a[i].first + b[j].first + c[k].first);
                }
            }
        }
    }

    cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
