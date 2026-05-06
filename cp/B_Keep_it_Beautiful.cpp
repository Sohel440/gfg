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
  
  int q;
  cin >> q;
  
 vector<int> ans;

 int c =0;
 int t;
 cin >> t;

 cout << 1;
 ans.push_back(t);
 for(int i = 1 ; i < q ; i++){
    //int t;
    cin >>t;

    if(c==0){
        if(ans.back() <= t){
            ans.push_back(t);
            cout << 1;
        }else{
            if(ans[0] >= t){
                ans.push_back(t);
                c++;
                cout << 1;
            }else{
                cout<< 0 ;
            }
        }
    }else if(c == 1){
        if(t >=ans.back() && t <= ans[0]){
            ans.push_back(t);
            cout << 1 ;
        }else{
            cout << 0 ;
        }
    }else{
        cout << 0 ;
    }
 }
 cout << '\n';
   //cout << i << endl;

  
  

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
