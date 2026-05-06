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


int dis(int x1 , int x2 , int y1 , int y2){
    return abs(x1-y1)+abs(x2-y2);

}
void solve() {
   vector<pair<int,int>> p;
   for(int i  =0 ; i < 3 ; i++){
    int x , y;
    cin >> x >> y;
    p.push_back({x,y});

   }
   
   int a =  1+ min(abs(dis(p[0].first  , p[0].second , p[1].first , p[1].second))  , abs(dis(p[0].first  , p[0].second , p[2].first , p[2].second)) );
cout << a << endl;

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
