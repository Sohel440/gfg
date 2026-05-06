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


void prime_vis(int *arr)
{

    for (ll i = 3; i <= 1000000; i += 2)
    {
        arr[i] = 1;
    }
    for (ll i = 3; i <= 1000000; i += 2)
    {

        if (arr[i] == 1)
        {
            for (ll j = i * i; j <= 1000000; j = j+ i)
            {
                arr[j] = 0;
            }
        }
    }
    arr[2] = 1;
    arr[1] = arr[0] =0;
}

int main()
{
    int arr[1000005] ={0};
    prime_vis(arr);
    
    int pre[1000005] ={0};

    for(int  i = 1 ; i<= 1000000 ; i++ ){
        pre[i] = pre[i-1] + arr[i];
    }


    int q;
    cin >> q;

    while(q--){

        int a , b;

        cin >> a >> b;


        cout << pre[b] - pre[a-1] << endl;
    }


    return 0;
}