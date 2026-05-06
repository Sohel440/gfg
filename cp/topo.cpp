// #include <bits/stdc++.h>
// #include <vector>
// using namespace std;
// #define ll long long
// #define scl(n) cin >> n;
// #define scc(c) cin >> c;
// #define fr(i, n) for (ll i = 0; i < n; i++)
// #define fr1(i, n) for (ll i = 1; i <= n; i++)
// #define fri(i, n) for (int i = 0; i < n; i++)
// #define fri1(i, n) for (int i = 1; i <= n; i++)
// #define pfl(x) printf("%lld\n", x)
// #define pb push_back
// #define l(s) s.size()
// #define asort(a) sort(a, a + n)
// #define all(x) (x).begin(), (x).end()
// #define dsort(a) sort(a, a + n, greater<int>())
// #define vasort(v) sort(v.begin(), v.end())
// #define vdsort(v) sort(v.begin(), v.end(), greater<int>())
// #define uniquee(x) x.erase(unique(x.begin(), x.end()), x.end())
// #define pn cout << endl;
// #define md 10000007
// #define inf 1e18
// #define debug cout << "Monti valo nei " << endl;
// #define ps cout << " ";
// #define Pi acos(-1.0)
// #define mem(a, i) memset(a, i, sizeof(a))
// #define tcas(i, t) for (ll i = 1; i <= t; i++)
// #define pcas(i) cout << "Case " << i << ": " << endl;
// int main()
// {
//     int k;
//     scl(k);
//    vector<ll> a;
//    fr1(i ,k){
//     a.push_back(i);
//    }

//    string str = "";
//    fr(i,k){
//     str+=to_string(a[i]);

//    }
//    cout << str << endl;
//    cout << str[k-1];

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{

   vector<int> a = {10, 20, 30, 40};
   int m = 2;
   int mid = 60;
   int cnt = 1;
   int sum = 0;
   bool f = true;
   for (int i = 0; i < a.size(); i++)
   {
      if (sum + a[i] > mid)
      {
         cnt++;
         if (cnt > m || a[i] > mid)
         {
            cout << "false" << endl;
           
         }
         sum = a[i];

      }else
         {
            sum += a[i];
         }
      
   }




   if (f)
      cout << "true" << endl;
}