#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
long long int moduo_korlam(long long int a , long long int b, long long int mod){
    long long int res = 1;

    while( b > 0 ){
        if(b & 1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}



void solve() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; ++i) {
        long long int n, k;
        cin >> n >> k;
        
        long long int a = moduo_korlam(2, n-1, 998244353);
        long long int result = moduo_korlam(a, k , 998244353);
        cout << result << endl;
    }
}



int main() {
   solve();
    //cout << moduo_korlam(343 , 2) %1000000007;
    //cout << (moduo_korlam(2,343 , 998244353) *(343)) %998244353;

    return 0;
}
