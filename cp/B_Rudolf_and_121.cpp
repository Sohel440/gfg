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
 
  int n ;
  cin >> n ;
  vi a(n);
  forn(i ,0 ,n) cin >> a[i];

  for(int i = 0 ; i < n-2 ; i++){
    if(a[i] == 0) continue;

    
        else if(a[i] < 0){
            cout << "NO"<< endl;
            return;
        }else{
        a[i+1] -=   2 * a[i];
    
   
        a[i+2] -= a[i];
        }

  }

  if(a[n-2] == 0 and a[n-1] == 0) cout << "YES"<< endl;
  else cout << "NO"<< endl;
  
  


}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        kaj();

    return 0;
}
