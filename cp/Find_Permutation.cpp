#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sohel() {
    int n;
        cin >> n;

        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            cin >> a[i];
        }

    vector<int> ans(n);

    // Sort a to ensure that the elements are in ascending order
    sort(a.begin(), a.end());

    // Create the permutation ans
    for (int i = 0; i < n; ++i) {
        ans[i] = a[i * 2];
    }

    // Output the permutation ans
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        

        sohel();
    } // added a closing brace for the while loop

    return 0;
} 