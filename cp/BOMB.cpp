#include <iostream>
using namespace std;

int solve(int n, int cnt) {
    if (n == 0) return cnt;

    int rem;
    int originalN = n; // Store the original value of n
    while (n) {
        rem = n % 10;
        if (rem == 4) cnt++;
        n = n / 10;
    }

    return solve(originalN - 1, cnt); // Decrease originalN instead of n
}

int countNumberswith4(int N) {
    int cnt = 0;
    return solve(N, cnt);
}

int main() {
    int N = 14;
    cout << "Count of numbers with digit 4 between 1 and " << N << ": " << countNumberswith4(N) << endl;
    return 0;
}
