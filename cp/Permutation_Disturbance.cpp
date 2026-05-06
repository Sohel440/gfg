// 6 2
// 6 9 7 1 8 3
// 5 8 8 1 4 1
// author : sohel mollik 
// dept : C.S.E
// university: RKMGEC


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
#define in(x) scanf("%d", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define nl printf("\n")

int SetBit (int n, int X) { return n | (1 << X); }
int ClearBit (int n, int X) { return n & ~(1 << X); }
int ToggleBit (int n, int X) { return n ^ (1 << X); }
bool CheckBit (int n, int X) { return (bool)(n & (1 << X)); }
int row[] = {1,0,-1,0};
int col[] = {0,1,0,-1};
const int mod = 1e9 + 7;

int  moduo_korlam(int a , int b){
    
   int res = 1;

    while( b > 0 ){

        if(b & 1){
            res = res * a;

        }
        a = a*a;

        b = b>> 1;

    }
    return res;

}
bool solve(int mid , vector<int> &a , int c){
int total =0;
    forn(i,0,a.size()){
        

        int side = (2LL* mid) + a[i];
        int area = side * side;

        total +=area;
        if(total > c){
           return false;
        }
    }

    return true;
}
void kaj() {
   
  
  int n ;
  cin >> n;

  vector<int> a(n);

  for(int i = 0 ; i < n ;i++){
    cin >> a[i];
  }

int  sohel = 0;
    for(int i = 0 ; i < n ; i++){
        if(i+1 == a[i]) 
        {
            if(a[i+1] != i+1)
            swap(a[i], a[i+1]);
            
            sohel++;
        }
    }

    cout << sohel << endl;

// allah bless you







}

int32_t main() {
    int t;
    cin >> t;
    while(t--) 
        kaj();


    return 0;
}