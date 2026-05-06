#include<bits/stdc++.h>
using namespace std;


#define      ll          long long int
#define      pb          push_back 
#define      Bishmillah  int main()
#define      MOD          1e9+7

int fastPower(int a , int n){

    if(n == 1){
        return a;
    }

    if(n&1){
        return a * fastPower(a , n/2) * fastPower(a ,n/2);

    }

    return fastPower(a , n/2) *fastPower(a , n/2);

}
Bishmillah{

   int t;
   cin >> t;
   while(t--){
       
       int a,n;
       cin >> a >> n;
       cout <<  fastPower(a,n);

   }

   return 0;
}