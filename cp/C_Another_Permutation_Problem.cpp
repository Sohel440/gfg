// #include<bits/stdc++.h>
// using namespace std;

// unordered_map<int,bool>mp;

// bool dfs(int n, int m) {
//     mp[n] = true;
//     if(n == m) return true;
//     if(n % 3 != 0) return false;  // n = 3x means x + 2x
   
//     bool x = dfs(n / 3, m);
//     bool Two_x = dfs(2LL * (n / 3), m);
//     return x or Two_x;
// }

// void kaj() {
//     int n;
//     cin >> n;

//     vector<long long > a(n);
//     for(int i= 0 ; i < n ; i++){
//         cin >> a[i];

//     }
//     sort(begin(a), end(a));

//     int cnt =0;
//     for(int i = 0 ; i < n ; i++){
//         int s = i+1 ;
//         int e = n-1;

//         while (s < e)
//         {
//             long long s = a[i] + a[s] + a[e];
//             long long ans = s *(s -a[i] ) *(s- a[s]) *(s -a[e]);
//             double res = sqrt(ans);

//             if(res > 0)  {cnt++ ; e++;}
//             else s++;



//         }
        
//     }
//     cout << cnt << endl;


// }

// int main() {
//     int t;
//     cin >> t;
//     while(t--) 
//         kaj();
// }


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
#define vi vector<int>
#define vpp vector<pair<int,int>>
#define vs vector<string>
#define vll vector<long long>
int row[] = {1,0,-1,0};
int col[] = {0,1,0,-1};
const int mod = 1e9 + 7;

void kaj() {
    int n ;
    cin >> n;
    
    int ans =0;

    forn(i , 0 , n){
         
         int sum =0;
         int  maxs = 0;

         forn(k,1 , n+1){
              if(k <= i){
                sum += k*k;
                maxs = max(maxs, k*k);
              }
              else{

                sum += (n + i + 1 - k) * k;
                maxs = max(maxs ,(n + i + 1 - k) * k );

              }
         }

         ans = max(ans , sum-maxs);


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
