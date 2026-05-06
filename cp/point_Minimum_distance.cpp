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

int main()
{

    int t;
    scl(t);

    while (t--)
    {
      int n ;
      scl(n);
      vector<int> arr(2*n);

      for(int i =0 ;i < 2 *n  ; i++) cin >> arr[i];
      
      sort(all(arr));
    vector<pair<int, int> > pts;
    for (int i = 0; i < n; i++) {
        pts.pb(make_pair(arr[i], arr[i + n]));
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += abs(pts[i].first - pts[i - 1].first) + abs(pts[i].second - pts[i - 1].second);
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << pts[i].first << ' ' << pts[i].second << endl;
    }
    }
    return 0;
}