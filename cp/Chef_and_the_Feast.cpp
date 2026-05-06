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
int powermod(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

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

int moduo_korlam(int a, int b, int m)
{

    int res = 1;

    while (b > 0)
    {

        if (b & 1)
        {
            res = res * a;
            res = res % m;
        }
        a = a * a;

        b = b >> 1;
    }
    return res % m;
}
bool solve(int mid, vector<int> &a, int c)
{
    int total = 0;
    forn(i, 0, a.size())
    {

        int side = (2LL * mid) + a[i];
        int area = side * side;

        total += area;
        if (total > c)
        {
            return false;
        }
    }

    return true;
}
int kdn(vi &a, int n)
{

    int mx = 0, sum = 0;
    forn(i, 0, n)
    {
        sum += a[i];
        if (sum < 0)
            sum = 0;
        mx = max(mx, sum);
    }

    return sum;
}

void kaj()
{

    int n;
    cin >> n;

    vi a(n);
    forn(i, 0, n)
    {
        cin >> a[i];
    }

    sort(rall(a));

    int sum = 0, ans = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            sum += a[i];
        }
        else
        {
            if (sum * i + a[i] >= (sum + a[i]) * (i + 1))
            {
                break;
            }
            sum += a[i];
        }
    }
    ans = sum * i;
    for (i = i; i < n; i++)
    {
        ans += a[i];
    }

    cout << ans << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        kaj();

    return 0;
}
