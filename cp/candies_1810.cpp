#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long
#define scl(n) cin >> n;
#define scc(c) cin >> c;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define fr1(i, n) for (ll i = 1; i <= n; i++)
#define fri(i, n) for (int i = 0; i < n; i++)
#define fri1(i, n) for (int i = 1; i <= n; i++)
#define pfl(x) printf("%lld\n", x)
#define pb push_back
#define l(s) s.size()
#define asort(a) sort(a, a + n)
#define all(x) (x).begin(), (x).end()
#define dsort(a) sort(a, a + n, greater<int>())
#define vasort(v) sort(v.begin(), v.end())
#define vdsort(v) sort(v.begin(), v.end(), greater<int>())
#define uniquee(x) x.erase(unique(x.begin(), x.end()), x.end())
#define pn cout << endl;
#define md 10000007
#define inf 1e18
#define debug cout << "Monti valo nei " << endl;
#define ps cout << " ";
#define Pi acos(-1.0)
#define mem(a, i) memset(a, i, sizeof(a))
#define tcas(i, t) for (ll i = 1; i <= t; i++)
#define pcas(i) cout << "Case " << i << ": " << endl;
ll fun(int n , int a , int b , int c ,int cnt){
    
    if(n ==0){
        return cnt;
    }
    if(n < 0) return INT_MIN;

    int takea =fun(n -a , a , b ,c , cnt + 1);
    int takeb = fun(n-b , a , b , c , cnt +1);
    int takec =fun(n -c  , a , b ,c , cnt+1);

    return max({takea,takeb,takec});
}
int main()
{
    int t ;
    scl(t);

    while(t--){
       
       ll n ;
       cin >> n;
       if(n  % 2 ==0 ) {cout << -1 << endl ; continue;}
     
       vector<ll> ans;

       while(n >1){
         
         if(((n+1) /2) %  2 == 1){
          ans.pb(1);
          n = (n+1)/2;
         }else{
          ans.pb(2);
          n =(n-1)/2;
         }
       }
  
       cout << ans.size() << endl ;
       reverse(begin(ans) , end(ans));

       for(auto i : ans) cout << i << " ";
       cout << endl;

    }
    return 0;
}