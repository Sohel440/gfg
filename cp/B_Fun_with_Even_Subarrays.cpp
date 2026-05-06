#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int target = a[n - 1];  
        int cnt = 0;
        int i = n - 2;

        while (i >= 0) {
            if (a[i] != target) {
                cnt++; 
                i -= (n - i - 1);  
            } else {
                i--; 
            }
        }

        cout << cnt << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
