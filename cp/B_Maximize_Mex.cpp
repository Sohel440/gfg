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

bool search(vi &x, int n, int k) {
    int l = 0, r = n-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (x[m] == k) return true;
        if (x[m] < k) l = m+1; else r = m-1;
    }
    return false;
}
int search_Ind(vi &x, int n, int k) {
    int l = 0, r = n-1;
    int ans=-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (x[m] == k) {ans = m ; r =m-1;}
        if (x[m] < k) l = m+1; else r = m-1;
    }
    return ans;
}

int cnt[200007];
void kaj() {
    int n ,x;
    cin >> n >>x;

    vi a(n);

    inp(a , n);
    for(int i = 0 ; i <=n ; i++){
        cnt[i]=0;
    }
    forn(i , 0 , n){
        if(a[i]<= n){
            cnt[a[i]]++;
        }
    }
    int ans =0;
    for(int i = 0  ; i <= n; i++){
        if(!cnt[i]){
        if(!cnt[i%x]){
                ans =i;
                break;
            }
            cnt[i%x]--;
        }else{
            int k = cnt[i]-1;
            cnt[i]=0;
            cnt[i%x] += k;
        }
    }
    cout << ans << endl;

}


int32_t main() {
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int t;
   cin >> t;
   while (t--)
        kaj();

    return 0;
}