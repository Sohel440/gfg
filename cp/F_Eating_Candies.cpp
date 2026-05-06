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

    // int n;
    // cin >> n;

    // vector<int> a(n);
    // forn(i, 0, n) cin >>a[i];

    // int  i =0, j=n-1;
    // int al =a[0] , bl=a[n-1];
    // int alc =1;
    // int blc=1;

    // int mx = 0;

    // while(i < j ){

    //     if(al == bl){
    //         mx = max(mx , alc + blc);
    //         al += a[++i];
    //         bl += a[--j];
           
    //         blc++;
    //         alc++;

    //     }
    //     if(al > bl) {
    //     bl += a[--j];
    //     blc++;
    //     }
    //     else {
    //         al += a[++i];
    //         alc++;
    //     }
    // }

    // //7 3 20 5 15 1 11 8 10

    // cout << mx << endl;

    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    map<int, int> sum_indx;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        sum_indx[sum] = i;
    }

    int ans = 0;
    sum = 0;
    for (int i = n; i >= 1; --i) {
        sum += a[i];
        if (sum_indx.find(sum) != sum_indx.end() && sum_indx[sum] < i) {
            ans = max(ans, (n - i + 1) + (sum_indx[sum] - 1 + 1));
        }
    }

    cout << ans << endl;

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
