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
        // ll x ;
        // cin >> x;
        // vector<int> a;
        // int cnt =3;
        // for(int i = 2 ; i < x;i++ ){

        //    if(x % i ==0){
        //     a.push_back(i);
        //     x = x /i;

        //    }
           

        // }
        // a.push_back(x);
        // sort(a.begin(),a.end());
        // set<int> st(a.begin() , a.end());

        // if(st.size() < 3 ){
 
        // cout << "NO" << endl; 
        // continue;
        // }
       
        //  vector<int> ans;
        //  for(auto i : a){
        //     ans.push_back(i);
        //  }
        //  int p = 1;
        //  for(int i = 2 ; i < a.size();i++)
        //  p *= a[i];
         
        //  a[2] = p;
         

        // cout << "YES" << endl;
        // for(int i = 0 ; i < 3 ;i++) cout <<a[i] << " " ;
        // cout << endl;

    //     int n;
	// 	cin >> n;
	// 	set<int> used;

	// 	for (int i = 2; i * i <= n; ++i) {
	// 		if (n % i == 0 && !used.count(i)) {
	// 			used.insert(i);
    //             cout << i << " ";
	// 			n /= i;
	// 			break;
	// 		}
	// 	}


	// 	for (int i = 2; i * i <= n; ++i) {
	// 		if (n % i == 0 && !used.count(i)) {
	// 			used.insert(i);
    //             cout << i << " ";
	// 			n /= i;
	// 			break;
	// 		}
	// 	}

    //    cout << used.count(n) << " ";
	// 	if (int(used.size()) < 2 || used.count(n) || n == 1) {
	// 		cout << "NO" << endl;
	// 	} else {
	// 		cout << "YES" << endl;
	// 		used.insert(n);
	// 		for (auto it : used) cout << it << " ";
	// 		cout << endl;
	// 	}

    int n ;
    cin >> n;
    set<int> st;
    for(int i = 2 ; i * i <= n ; i++){
        
        if(n %i ==0 && !st.count(i)){
            st.insert(i);
            n /= i;
            break;
        }
    }

    for(int i = 2 ; i * i <= n ; i++){
        
        if(n %i ==0 && !st.count(i)){
            st.insert(i);
            n /= i;
            break;
        }
    }
    
    if(n == 1 || st.size() < 2 || st.count(n) ){
        cout << "NO" << endl;
    }
    else{
        st.insert(n);;
        cout << "YES" << endl;
        for(auto i : st) cout << i << " ";
        cout << endl;
    }

    }

    return 0;
}