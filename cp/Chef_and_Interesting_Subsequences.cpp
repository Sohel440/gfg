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
#define vpp vector<pair<int, int>>
#define vs vector<string>
#define vll vector<long long>
#define in(x) scanf("%d", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define nl printf("\n")
int powermod(int x, int y, int p){int res = 1;x = x % p;if (x == 0)return 0;while (y > 0) { if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p; } return res;}
int moduo_korlam(int a, int b, int m){int res = 1;while (b > 0) {if (b & 1) {res = res * a;res = res % m;}a = a * a;b = b >> 1; }return res % m;}
int kdn(vi &a, int n){int mx = 0, sum = 0;forn(i, 0, n) {sum += a[i];if (sum < 0)sum = 0;mx = max(mx, sum);}return sum;}

// Graph-dfs
//  bool gone[MN];
//  vector<int> adj[MN];
//  void dfs(int loc){
int SetBit(int n, int X) { return n | (1 << X); }
int ClearBit(int n, int X) { return n & ~(1 << X); }
int ToggleBit(int n, int X) { return n ^ (1 << X); }
bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }
int row[] = {1, 0, -1, 0};
int col[] = {0, 1, 0, -1};
const int mod = 1e9 + 7;

int n , m;
 vi a;


 int dp[70][7000][70];

int dp_tei_korbo(int ind , int sum , int k){
   if(ind >= n){
      if(sum == 0 && m == k)
    return 1;

    return 0;

   }
   if(dp[ind][sum][k]!= -1 ) return dp[ind][sum][k];
   if(sum == 0 && m == k){
    return 1;

   }

    int ans =0;
    ans += dp_tei_korbo(ind + 1 , sum , k);
    if(sum - a[ind] >= 0 && k+1 <= m){
        ans += dp_tei_korbo(ind + 1 , sum - a[ind] ,k+1 );

    }

    return dp[ind][sum][k]= ans;
    return dp[ind][sum][k];


}
void kaj()
{
    memset(dp , -1 ,sizeof(dp));
    
    cin >> n >> m;
    if (m > n) {
        cout << 0 << endl;
        return;
    }
    a.clear();
    a.resize(n);


    forn(i , 0 , n) cin >> a[i];

    sort(all(a));
    int sum =0;
    for(int i =0 ; i < m ; i++){
        sum += a[i];

    }
    
    cout << dp_tei_korbo(0 , sum , 0)<< endl;



}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        kaj();

    return 0;
}
