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
#define pr(x)  cout << "x" << endl;
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
       ll sum =0;
       vector<ll> a(n);

       for(int i =0 ; i < n/2 ; i++){
        a[i] = 2 * (i +1) ;
        sum += a[i];
       }


       int i =0; int k =0;
       bool flag = true;

       for(i = n/2 ; i < n ; i++){
        if(i == n-1){
           if(sum %2 != 0){
                flag = false;
                a[i]  = sum;
            }
        }else{

            a[i] = 2 * k + 1;
            k++;
            sum -= a[i];
        }
       }


       if(flag == true){
        cout << "NO" << endl;
       }else{
        cout << "YES" << endl;
      for(auto i : a) cout << i << " " ;

       pn
       }

 
    //    ll n ;
    //    scl(n);
    //    ll temp = n;
    //    if( n == 2){
    //     cout << "NO" << endl;
    //     continue;
    //    }
      
    //    while(n % 2 == 0){
    //         n /= 2;
           
       
    //    } 
    //    // cout << n <<endl;

    //    if(n != 1){
    //     cout << "NO" << endl;
    //     continue;
    //    }
    //    n = temp;
    //    vector<ll> even;

    //    while(n > 0 ){
    //     even.pb(n);
    //     n = n -2;

    //    }

    //   // for(auto i : even){cout << i << " ";}
    //    //cout << endl;
    //    vector<ll> odd(even.size());

    //    for(int i = 0 ; i < even.size() ; i++){
    //     odd[i] = even[i]-1;
    //    }

    //    odd[0 ] = odd[0] + odd.size();
    //    ll sum1 =0, sum2 =0;
    //   for(auto i : even){sum1 += i;}
    //   for(auto i : odd){sum2 +=i ;}

    //    if(sum1 == sum2){
    //    cout << "YES" << endl;
    //   reverse(all(even));
    //   reverse(all(odd));
    //   for(auto i : even){cout << i << " ";}
    //   for(auto i : odd){cout << i << " ";}
    //  pn
    //    }
    //   else {
    //     cout << "NO" << endl; 
    //    }


    }
    return 0;
}