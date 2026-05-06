
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
  
 int n;
 cin >> n;

 string s;
 cin >> s;
 string res="";
 while(!s.empty()){
    int x;

    if(s.back() == 'a' || s.back() =='e'){
        x = 2;
    }else{
        x= 3;
    }

    while(x--){
        res+= s.back();
        s.pop_back();
    }
    res+=".";
 }
  
res.pop_back();
reverse(begin(res), end(res));
cout << res<< endl;

  

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
