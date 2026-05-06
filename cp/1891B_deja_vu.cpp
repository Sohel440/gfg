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
#define debug cout << "sohel valo nei " << endl;
#define ps cout << " ";
#define Pi acos(-1.0)
#define mem(a, i) memset(a, i, sizeof(a))
#define tcas(i, t) for (ll i = 1; i <= t; i++)
#define pcas(i) cout << "Case " << i << ": " << endl;
double dist(int x1 , int y1 , int x2 , int y2){
    double ans = sqrt((x1-x2) * (x1 - x2) + (y1-y2) * (y1-y2));
    return ans;

}
void solve()
{
    int px, py, a1,a2 , b1,b2;
    cin >> px >> py >> a1 >> a2 >> b1 >> b2;
    
    double ap = dist(px ,py , a1 , a2);
   // cout << "ap " << ap << endl;
    double bp = dist(px , py , b1 , b2);
      //cout << "bp " << bp << endl;
    double oa = dist(0 , 0 , a1 , a2);
      //cout << "oa " << oa << endl;
    double ob = dist(0 , 0 , b1 , b2);
  //cout << "ob " << ob << endl;
    double ab  = dist(a1 , a2 , b1 , b2);
    
    double r1 = min( ap , bp);
    double r2 = min( oa , ob);

    double ans = max(r1 , r2);

    // if(ab > 2.0*ans) {cout <<setprecision(10)<< (double)ab/2 << endl; return;}
    if((min(ap , bp) == ap && min(ob , oa) == oa) ||(min(ap , bp) == bp && min(ob , oa) == ob) ){

    }else{

      if (2 * ans < ab) ans =ab/2;
      
    }

    cout << setprecision(10)<<fixed<< ans <<endl;


}
int main()
{

    int t;
    cin >> t;
    
    while (t--)
    {

        solve();
    }
    return 0;
}