#include <iostream>
#include <string>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    
    string s;
    cin >> s;
    
    int n = s.size();
    
    // First pass: Make the string a palindrome by copying the known characters
    for (int i = 0; i < n; i++) {
        if (s[i] != '?' && s[n - i - 1] == '?') {
            s[n - i - 1] = s[i];
        } else if (s[i] == '?' && s[n - i - 1] != '?') {
            s[i] = s[n - i - 1];
        }
    }
    
    // Count existing 0s and 1s after first pass
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') a--;
        else if (s[i] == '1') b--;
    }
    
    // Second pass: Fill remaining '?' with '0' or '1'
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == '?' && s[n - i - 1] == '?') {
            if (a >= 2) {
                s[i] = s[n - i - 1] = '0';
                a -= 2;
            } else if (b >= 2) {
                s[i] = s[n - i - 1] = '1';
                b -= 2;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    // Handle the middle character if the string length is odd
    if (n % 2 == 1 && s[n / 2] == '?') {
        if (a > 0) {
            s[n / 2] = '0';
            a--;
        } else if (b > 0) {
            s[n / 2] = '1';
            b--;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    
    // Final check: Verify the palindrome and count constraints
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n - i - 1]) {
            cout << -1 << endl;
            return;
        }
    }
    
    if (a == 0 && b == 0) {
        cout << s << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
