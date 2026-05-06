
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
  
 int n , k;
 cin >> n >> k;

 vector<int> a(n);

 for(int i = 0 ; i < n ; i ++){
    cin>> a[i];
    //a[i]--;

 }

 int ex =0;

 for(int i = 1 ; i <= n  ; i++){
    if(a[i-1] % k != i %k){
      ex++;
    }
 }

if(ex ==0){
    cout << 0 << endl;

}else if(ex == 2){
    cout << 1 << endl;
}else{
    cout << -1 << endl;

}
  
  

} 



int main() {
   int t;
   cin>> t;
   while(t--)
   solve();
    //cout << moduo_korlam(343 , 2) %1000000007;
    //cout << (moduo_korlam(2,343 , 998244353) *(343)) %998244353;

    return 0;
}
