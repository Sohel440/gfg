#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool can_form_sum(int L, int R, long long S) {
    vector<int> numbers;
    for (int i = L; i <= R; ++i) {
        numbers.push_back(i);
    }
    
    int n = numbers.size();
    // Use a bitmask to check all possible subsets
    for (int mask = 1; mask < (1 << n); ++mask) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += numbers[i];
            }
        }
        if (sum == S) {
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int L, R;
        long long S;
        cin >> L >> R >> S;
        
        // Calculate minimum and maximum sum
        long long min_sum = L;
        long long max_sum = (R - L + 1) * (L + R) / 2;
        
        // Check if S is within the feasible range
        if (S < min_sum || S > max_sum) {
            cout << 0 << endl;
        } else {
            // Check if S can be formed by some subset
            if (can_form_sum(L, R, S)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
