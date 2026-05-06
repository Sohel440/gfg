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

int main() {
    int t;
    scl(t);

    while (t--) {
        //   long long n;
        // cin >> n;

        // string str;
        // cin >> str;

        // long long res = 1;
        // int mod1 = 1e9 + 7;

        // for (int i = 2; i < str.size(); i += 2) {
        //     int cnt = 0;
        //     int curr = str[i] - '0';
        //     int a = str[i - 1] - '0';
        //     int b = str[i - 2] - '0';

        //     if (curr == (a & b)) cnt++;
        //     if (curr == (a | b)) cnt++;
        //     if (curr == (a ^ b)) cnt++;

        //     res = (res * cnt) % mod1;
        // }

        // if (res == 0)
        //     cout << 0 << endl;
        // else
        //     cout << res << endl;
        long long n, k;
	    cin >> n >> k;
	    if (k < n + n/2 || k % 2 != (n/2) % 2 || k > 199999*(n/2)){
	        cout << -1 << "\n";
	        continue;
	    }
	    long long r = k - n - n/2;
	    for(long long i = 0; i < n; ++i){
	        long long mx = min(r, 99998LL);
	        r -= mx;
	        cout << 1 + (i%2) + mx << " ";
	    }
	    cout << "\n";
    }

    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define scl(n)              cin >> n
#define scc(c)              cin >> c
#define fr(i, n)            for (ll i = 0; i < n; i++)
#define fr1(i, n)           for (ll i = 1; i <= n; i++)
#define pfl(x)              cout << x << endl
#define pb                  push_back

int main() {
    int t;
    scl(t);

    while (t--) {
        int n;
        cin >> n;

        int cost = ceil(0.2 * n);  // Calculate 20% of n as cost
        int ans = ceil(100.0 / cost);  // Calculate ans as 100 / cost
        pfl(ans);
    }

    return 0;
}
*/

// #include <bits/stdc++.h>
// using namespace std;


// int main() {
//         long long n;
//         cin >> n;

//         string str;
//         cin >> str;

//         long long res = 1;
//         int mod1 = 1e9 + 7;

//         for (int i = 2; i < str.size(); i += 2) {
//             int cnt = 0;
//             int curr = str[i] - '0';
//             int a = str[i - 1] - '0';
//             int b = str[i - 2] - '0';

//             if (curr == (a & b)) cnt++;
//             if (curr == (a | b)) cnt++;
//             if (curr == (a ^ b)) cnt++;

//             res = (res * cnt) % mod1;
//         }

//         if (res == 0)
//             cout << 0 << endl;
//         else
//             cout << res << endl;
    

//     return 0;
// }

/*#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    if (K % 2 == 1  K < N / 2  K > N * (100000 + 1)) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> A(N, 1);

    int remainingSum = K - N / 2;

    for (int i = 0; i < N; i += 2) {
        if (remainingSum >= 100000 - 1) {
            A[i] = 100000;
            remainingSum -= (100000 - 1);
        } else {
            A[i] += remainingSum;
            break;
        }
    }

    for (int i = 1; i < N; i += 2) {
        if (remainingSum >= 1) {
            A[i] = 2;
            remainingSum--;
        } else {
            break;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }

    cout << endl;

    return 0;
}*/