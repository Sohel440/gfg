//Let's start with the name of Allah
//sohel440
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <iostream>
#include <bits/stdc++.h>
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
#define inp(a, n) forn(i,0,n) cin >> a[i]
void yes(){cout << "YES"<< endl;};
void no(){cout << "NO"<< endl;};


void kaj() {
   
   int n;
   cin >> n;

   vi a(n);
   inp(a , n);

   sort(all(a));

   int prev = a[0];
   forn( i , 1  , n){
       int mid = ceil((prev+a[i])/2);
       prev = mid;
   }
   cout << prev << endl;
    
}


int32_t main() {
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int t;
   cin >> t;
   while (t--)
        kaj();

    return 0;
}