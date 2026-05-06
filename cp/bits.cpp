#include <bits/stdc++.h>
// #include <bits>
#include <bitset>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define ll long long
#define scl(n) cin >> n;
#define scc(c) cin >> c;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define fr1(i, n) for (ll i = 1; i <= n; i++)
#define fri(i, n) for (int i = 0; i < n; i++)
#define fri1(i, n) for (int i = 1; i <= n; i++)
#define pfl(x) printf("%lld\n", x)
#define pb push_back
#define l(s) s.size()
#define asort(a) sort(a, a + n)
#define all(x) (x).begin(), (x).end()
#define dsort(a) sort(a, a + n, greater<int>())
#define vasort(v) sort(v.begin(), v.end())
#define vdsort(v) sort(v.begin(), v.end(), greater<int>())
#define uniquee(x) x.erase(unique(x.begin(), x.end()), x.end())
#define pn cout << endl;
#define md 10000007
#define inf 1e18
#define debug cout << "Monti valo nei " << endl;
#define ps cout << " ";
#define Pi acos(-1.0)
#define mem(a, i) memset(a, i, sizeof(a))
#define tcas(i, t) for (ll i = 1; i <= t; i++)
#define pcas(i) cout << "Case " << i << ": " << endl;
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

void bintodec(int n ){
   for(int i = 10 ; i >=0 ; i--){
      cout << ((n>>i) & 1);
   }
   cout << endl;
}
int main(){
  
//    int n;
//    scl(n);
 /********************ceck for the number is power of 2 or not ***********************/
// unsigned int A =  n & (n-1);
// if( !A && n) cout << "YES" << endl;
// else cout << " NO ";
/************************************************************/

// int cnt =0;
// while(n){
//    n = n & (n-1);
//    cnt++;

// }                        as well as we use the  // __builin_popcount(int);

// cout << cnt << endl ;   


/*********************************/
// int a = 1<<4 ;  pow() same as 
// cout << a <<endl;

/****************************************/
      
      //  if (std::has_single_bit(n)) // `ispow2` before P1956R1
      
        //     std::cout << " = 2^" << std::log2(n) << " (is power of two)";
        // std::cout << '\n';


// int cnt = __builtin_popcount(n);
// cout << cnt << endl;
 

//  int n , m , k ;
//  scl(n);scl(m);scl(k);
//  vector<int> a(m);
//  fr(i , m){
//     scl(a[i]);
//  }
//  int val;

//  scl(val)
//  int cnt =0;
//  fr(i , m){
//     int diff = val xor a[i];

//     if(__builtin_popcount(diff) <= k) cnt++;

//  }


//  cout << cnt << endl;

/***********************/

//1000000001
//(msb)   (lsb)

//set_bit



// // unsigned int a = 5>>2;
// int a =5;
// bintodec(a);

// // cout << a << endl;
// int b = n & a;  
// cout << b << endl;
/*************************/
// bintodec(n);
// int a = 1 << 0;
// bintodec(a);
// // int b = ;
// // bintodec(b);
// if( !(n & a)){
//    cout << "even" << endl;
// }else{
//    cout <<"ODD"<<endl;
// }
/****************************/


  

  //multiply by 2;
//   cout <<"multiply: " <<  (n << 1) << endl;
//   cout << "divide " << (n>>1)<< endl;

// for(char c = 'A' ; c <='E' ;c++){
//    bintodec(int(c));
// }
// cout << "small Alpha : ";
// for(char c = 'a' ; c <='e' ;c++){
//    bintodec(int(c));
// }

// char a = 'A';
// char c = a | (1 << 5) ;



// cout << c << endl;//upper to lower 

// cout <<char( c & (~(1<<5))) << endl;// lower to upper

/*************************/

// // short trick

// char B ='B';
// char b = 'b';
// cout << char(B |' ') << endl; // upper to lower
// cout << char(b & '_') << endl; //lower  to upper



/**************LSB*****************/


 int a = (5 >> 2) ;
 int c ;
 cin >> c;
 cout << c << endl;
 bintodec(a) ;

   return 0;
}