#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <iostream>
#include <bits/stdc++.h>
//#include "utilities.cpp"
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define forn(i, x, n) for (int i = x; i < n; i++)
#define for1(i, x, n) for (int i = x; i <= n; i++)
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

    int n , k;
    cin >> n >> k;

    vi a(n);
    vi b(n);

    int k1 = k*2;
    int k2 = k*2;

    unordered_map<int, int> mp;
    forn(i, 0, n) cin >> a[i];
    forn(i, 0 ,n) cin >> b[i];

    for(auto i : a){
        mp[i]++;
    }

    vi ans1 , ans2;
    for1(i, 1 , n){

        if(mp[i] == 1 && k1 >  0 ){
            k1--;
            k2--;
            ans1.pb(i);
            ans2.pb(i);
        }
    }

    if(ans1.size() % 2 == 1 ){
        k1++;
        k2++;
        ans1.pop_back();
        ans2.pop_back();

    }

    for1(i, 1, n){
        if(mp[i] == 2 && k1 >0 ){
            k1-= 2;
            ans1.pb(i);
            ans1.pb(i);
        }
    }
    for1(i, 1, n){
        if(mp[i] == 0 && k2 >0 ){
            k2-= 2;
            ans2.pb(i);
            ans2.pb(i);
        }
    }

    for(auto i : ans1) cout << i << " ";
    cout << endl;
    for(auto i : ans2) cout << i << " ";
    cout << endl;

}

int32_t main() {
    int t;
    cin >> t;
    while(t--) 
        kaj();


    return 0;
}

