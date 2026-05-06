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
    cin >> t;
    while (t--)
    {

        int n;
        scl(n);
        vector<ll> a(n);
       

        fr(i, n) scl(a[i]);

        map<int, int> mp;

        fr(j, n)
        {
            int b = a[j];
            while (b % 2 == 0)
            {
                mp[2]++;
                b /= 2;
            }

            for (int i = 3; i * i <= b; i += 2)
            {
                while (b % i == 0)
                {
                    mp[i]++;
                    b /= i;
                }
            }

            if (b > 2)
                mp[b]++;
        }
 
        bool flag = true;
        for (auto u : mp)
        {
            if (u.second % n != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
       
    }

    return 0;
}