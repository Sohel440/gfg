#include<bits/stdc++.h> 
using namespace std;
#define int  long long  


int kaj (int a){
  
   int x = sqrt(a) + 2;
   while(x * x > a ) x--;


   return x;
 


}

signed main(){

   int tt;
   cin >> tt;


   while(tt--){

     int n ;
     cin>> n;

     cout << kaj(n-1LL) << endl;


      
   }

}