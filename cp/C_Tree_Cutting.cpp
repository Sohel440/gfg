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
int powermod(int x, int y, int p){int res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
 
//Graph-dfs
// bool gone[MN];
// vector<int> adj[MN];
// void dfs(int loc){
int SetBit (int n, int X) { return n | (1 << X); }
int ClearBit (int n, int X) { return n & ~(1 << X); }
int ToggleBit (int n, int X) { return n ^ (1 << X); }
bool CheckBit (int n, int X) { return (bool)(n & (1 << X)); }
int row[] = {1,0,-1,0};
int col[] = {0,1,0,-1};
const int mod = 1e9 + 7;

int  moduo_korlam(int a , int b , int m){
    
   int res = 1;

    while( b > 0 ){

        if(b & 1){
            res = res * a;
            res = res %m;
        }
        a = a*a;

        b = b>> 1;

    }
    return res %m;

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
int kdn(vi &a , int n){

    int mx = 0 , sum =0;
    forn(i, 0, n){
        sum += a[i];
        if(sum < 0) sum =0;
        mx = max(mx , sum);
    }

    return sum;

}
const int N =2e5+5; 
vector<int> adj[N];
int sz[N];
int cnt ;
int n ,k ;
void dfs(int u , int p , int mid){

    sz[u] = 1;
    for(auto v : adj[u]){
        if(v == p) continue;
        dfs(v , u , mid);
        sz[u] += sz[v];

    }

    if(sz[u] >= mid && cnt < k and p != 0){
        cnt ++;
        sz[u]=0;

    }
}
void kaj() {

    cin >> n >> k;
   
   forn(i , 0 , n-1 ){
    int u , v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
   }

   int s = 1 , e = n,ans =0;
   
   while(s <= e){

    int mid = (s + e)>> 1;
    for(int i = 1; i <= n ; i++) sz[i] = 0;
    cnt =0;
    dfs(1 , 0 , mid);

    if(cnt >= k && sz[1] >=mid){
        ans = max(ans , mid);
        s = mid + 1;

    }else{
        e = mid -1;
    }
   }
   cout << ans << endl;


for(int i=0; i<=n; i++) {
        adj[i].clear();
        sz[i] = 0;
    }
   


}

int32_t main() {
    int t;
    cin >> t;
    while(t--) 
        kaj();


    return 0;
}

