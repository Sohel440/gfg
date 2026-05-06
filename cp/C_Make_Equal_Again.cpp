#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <iostream>
#include <bits/stdc++.h>
// #include "utilities.cpp"
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define forn(i, x, n) for (int i = x; i < n; i++)
#define fore(i, x, n) for (int i = x; i <= n; i++)
#define vi vector<int>
#define vpp vector<pair<int,int>>
#define vs vector<string>
#define vll vector<long long>

int SetBit (int n, int X) { return n | (1 << X); }
int ClearBit (int n, int X) { return n & ~(1 << X); }
int ToggleBit (int n, int X) { return n ^ (1 << X); }
bool CheckBit (int n, int X) { return (bool)(n & (1 << X)); }
int row[] = {1,0,-1,0};
int col[] = {0,1,0,-1};
const int mod = 1e9 + 7;

void kaj() {
   int n ;
   cin >> n;

  vector<int> a(n);
  forn(i ,0 ,n){
    cin >> a[i];
  }


  int left =1;
  int right =1;

  forn(i, 1,n){
    if(a[i-1] != a[i]) break;
    left++;
  }
for(int i = n-2 ; i>= 0 ; i--){
    if(a[i] != a[i+1]) break;
    right++;
}

int sum =0;
if(a[0] == a[n-1]){
    sum = min ( n , left+ right);

}else{

    sum = min(n ,max(left , right));

}

cout << n - sum << endl;


}

int32_t main() {
    int t;
    cin >> t;
    while(t--) 
        kaj();


    return 0;
}
