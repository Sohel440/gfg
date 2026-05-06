// #include <bits/stdc++.h>
// using namespace std;

// #define ll              long long int
// #define pb              push_back
// #define Bishmillah      int main()
// #define MOD             1000000000
// #define fr0(i, n)       for (ll i = 0; i < n; i++)
// #define fr1(i, n)       for (ll i = 1; i <= n; i++)
// #define V               vector
// #define st              set
// #define ins             insert
// #define mii             map<int, int>
// #define pqr             priority_queue<ll>
// #define yes             cout << "YES"<< endl
// #define No             cout << "NO"<< endl

// float solve(int n , int p){
//   float inc = 0.1;
//   int s = 0, e = n;
//   float ans =-1;;

//   while(s <= e){

//     int mid = (s+e)>>1;
//     if(mid * mid == n){
//       return mid;
//     }
//     else if(mid *mid < n ){
//       ans = mid;
//       s = mid +1;
//     }else{
//       // ans = mid;
//       e = mid -1;
//     }
//   }
   
//   fr1(i ,p){
//     while(ans * ans <= n){
//       ans = ans +inc;
//     }
//     ans = ans- inc;
//     inc =inc /10;
//   }

//   //cout << ans << endl;
//    return ans;
// }

// Bishmillah
// {

//   int t;
//   cin >> t;
//   while (t--)
//   {
//     ll n , p;
//     cin >> n >> p;
//   cout << solve(n,p) << endl;
   
//   }

 


//   return 0;
// }


#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007

int computePower(int base, int f) {
    int result = 1;
    while (f > 0) {
        if (f & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        f >>= 1;
    }
    return result;
}

string cToB(int n) {
    string sohel = "";
    while (n != 0) {
        if (n & 1) {
            sohel += '1';
        } else {
            sohel += '0';
        }
        n >>= 1;
    }
    reverse(sohel.begin(), sohel.end());
    return sohel;
}

void solve() {
    int inp;
    cin >> inp;

    string BR = cToB(inp);
    string pattern = "11";
    int pp = 0;
    int position = 0;

    for (int i = 0; i < BR.length(); i++) {
        if (BR[i] == pattern[pp]) {
            pp++;
            if (pp == 2) {
                position = i + 1;
                break;
            }
        }
    }

    if (pp <= 1) {
        cout << 1 << endl;
        return;
    }

    int cntZ = 0;
    for (int i = position; i < BR.length(); i++) {
        if (BR[i] == '0') {
            cntZ++;
        }
    }

    cout << computePower(2, cntZ) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}