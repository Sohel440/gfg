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
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
ll a[10][10]= { 1 ,1 ,1 ,1, 1 ,1 ,1 ,1 ,1, 1,
                1 ,2 ,2 ,2, 2 ,2 ,2 ,2 ,2, 1,
                1 ,2 ,3 ,3, 3 ,3 ,3 ,3 ,2, 1,
                1 ,2 ,3 ,4, 4 ,4 ,4 ,3 ,2, 1,
                1 ,2 ,3 ,4, 5 ,5 ,4 ,3 ,2, 1,
                1 ,2 ,3 ,4, 5 ,5 ,4 ,3 ,2, 1,
                1 ,2 ,3 ,4, 4 ,4 ,4 ,3 ,2, 1,
                1 ,2 ,3 ,3, 3 ,3 ,3 ,3 ,2, 1,
                1 ,2 ,2 ,2, 2 ,2 ,2 ,2 ,2, 1,
                1 ,1 ,1 ,1, 1 ,1 ,1 ,1 ,1, 1
                
               };
int main() {
    int t;
    scl(t); 

     while (t--) {
         char ch[10][10];
        
        for(int i = 0 ; i < 10 ; i++){
            for(int j = 0 ; j < 10 ; j++){
                cin >> ch[i][j];
            }
        }
        ll ans =0;
        for(int i =  0 ; i < 10 ; i++){
            for(int j =0; j <10 ;j++){
               
              if(ch[i][j] == 'X'){
                ans += a[i][j];
              }

            }

        }
        cout << ans << endl;
        
    }

    return 0;
}

