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




 
void kaj()
{
    int n, m, k;
cin >> n >> m >> k;
vi a(n), b(m);  // Assuming "vi" is a vector<int> type alias
for(int i = 0; i < n; i++)
    cin >> a[i];
for(int i = 0; i < m; i++)
    cin >> b[i];

int cnt = 0;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        if(a[i] + b[j] <= k) {
            cnt++;
        }
    }
}

cout << cnt << endl;

}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        kaj();

    return 0;
}
