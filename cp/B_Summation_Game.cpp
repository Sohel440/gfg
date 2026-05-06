



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
    int n , k , x;
    cin >> n >> k >> x;

    vector<int> a(n+1);
    fore(i,1, n) cin >> a[i];
    sort(all(a));
    vector<int> pr(n+1);
    pr[1] = a[1];

    fore(i, 2, n){
        pr[i] = pr[i-1] + a[i];
    }
    int mx = INT_MIN;

    for(int i = n ;i >= 0 ; i--){

        int idx = n-i;
        if(idx > k) break;
        int p = min(i , x);

        int ans = (pr[i-p] -(pr[i] - pr[i-p]));
        mx = max(mx , ans);


    }
    cout << mx << endl;

}

int32_t main() {
    int t;
    cin >> t;
    while(t--) 
        kaj();


    return 0;
}
