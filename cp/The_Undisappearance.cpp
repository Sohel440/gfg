#include <bits/stdc++.h>
using namespace std;

int countValidSubarrays(const vector<int>& A) {
    int N = A.size();
    int count = 0;
    unordered_map<int, int> freq;
    
    int left = 0;
    for (int right = 0; right < N; ++right) {
        freq[A[right]]++;
        
        while (freq[1] > 0 && freq[2] > 0 && freq[3] > 0) {
            count += N - right; 
            freq[A[left]]--; 
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        cout << countValidSubarrays(A) << endl;
    }
    
    return 0;
}