#include <iostream> 
#include <vector> 
#define MOD 1000000007 
 
using namespace std; 
 
long long exp(long long a, long long b) { 
    long long res = 1; 
    while (b) { 
        if (b & 1) { 
            res = (res * a) % MOD; 
        } 
        a = (a * a) % MOD; 
        b >>= 1; 
    } 
    return res; 
} 
 
int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(0); 
     
    int tc; 
    cin >> tc; 
    vector<long long> results(tc); 
     
    for (long long t = 0; t < tc; ++t) { 
        int n; 
        cin >> n; 
        long long ans = 0; 
        long long prev = 0; 
         
        for (long long i = 1; i <= n; ++i) { 
            long long curr = prev; 
            curr = (curr * 2) % MOD; 
            curr = (curr + ((i - 1) * (i - 1)) % MOD) % MOD; 
            ans = (ans + (curr * exp(2, n - i)) % MOD) % MOD; 
            prev = curr; 
        } 
         
        ans = (ans * 2) % MOD; 
        results[t] = ans; 
    } 
     
    for (const auto &result : results) { 
        cout << result << endl; 
    } 
     
    return 0; 
}