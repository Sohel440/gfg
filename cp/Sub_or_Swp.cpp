#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void solve() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; ++i) {
        int x , y;
        cin >> x>> y;

        cout << __gcd(x,y)<< endl;
    }
}

int main() {
    solve();
    return 0;
}
