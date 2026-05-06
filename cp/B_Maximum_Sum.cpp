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
void kaj() {

    int n ,k;
    cin >> n >> k;
    int sum =0 , s =0 , ans =0;
    vector<int> a(n);

    forn(i ,0 , n) {
         cin >> a[i];
         sum += a[i];
         s += a[i];
         if(s < 0){
            s =0;

         }
         ans = max(ans , s);

    }

   
    
    

     sum=((sum-ans)%mod+mod)%mod;
	ans%=mod;
	cout<<(sum%mod+((powermod(2,k,mod)%mod*ans%mod)%mod)%mod)%mod<<endl;

   


}

int32_t main() {
    int t;
    cin >> t;
    while(t--) 
        kaj();


    return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int solve(const vector<int>& candies) {
//     int n = candies.size();
//     if (n < 2) return 0; // Edge case

//     int i = 0, j = n - 1;
//     int aliceTotal = candies[i], bobTotal = candies[j];
//     int aliceCount = 1, bobCount = 1;
//     int maxCandies = 0;

//     while (i < j) {
//         if (aliceTotal == bobTotal) {
//             maxCandies = max(maxCandies, aliceCount + bobCount);
//             aliceTotal += candies[++i];
//             bobTotal += candies[--j];
//             aliceCount++;
//             bobCount++;
//         } else if (aliceTotal < bobTotal) {
//             aliceTotal += candies[++i];
//             aliceCount++;
//         } else {
//             bobTotal += candies[--j];
//             bobCount++;
//         }
//     }

//     return maxCandies;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> candies(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> candies[i];
//         }
//         cout << solve(candies) << endl;
//     }
//     return 0;
// }
