
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
    cin>> n;

    string s;
    cin >> s;


    vector<int> p(n);

    p[0] =  s[0]== '1';

    for(int i = 1 ; i < n ; i++){
        p[i] = p[i-1] + (s[i] == '1');
    }
    
    int ans =-1;


    auto getsum = [&](int l , int r){
        if(l == 0) return p[r];
        return p[r] - p[l-1];
    };

    if(getsum (0 , n-1 ) >= (n+1)/2){
        ans =0;

    }

    for(int i= 0 ; i < n ; i++){

        int l1 = getsum(0 , i);
        int l0 = i+1 -l1;

        int r1 = getsum(i+1 , n-1);
        int r0 = n- (i+1 ) -r1;

        if(l0 >= l1 and r1 >= r0){
            if( abs(n - 2 * ans ) > abs(n - 2 * (i+1))){
                ans = i+1;

            }
        }
       
    }


 if (ans == -1) cout << 0 << endl;
        cout << ans << endl;



}

int32_t main() {
    int t;
    cin >> t;
    while(t--) 
        kaj();


    return 0;
}
