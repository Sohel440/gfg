//C. Assembly via Minimums
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <iostream>
#include <bits/stdc++.h>
// #include "utilities.cpp"
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define forn(i, x, n) for (int i = x; i < n; i++)
#define vi vector<int>
#define vpp vector<pair<int,int>>
#define vs vector<string>
#define vll vector<long long>
int row[] = {1,0,-1,0};
int col[] = {0,1,0,-1};
const int mod = 1e9 + 7;
std::unordered_set<char> u = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

   std::unordered_set<char> l = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

   char B = 'B';
   char b = 'b';

void kaj() {
    
//   int n ;
//   cin >> n;

//   int s=0;

//   if(n % 2== 0){
//     for(int i = 1 ; i <= n/2 ; i++)   // 1  2  3 4 5
//        s += i*2;



//   }
//   else{
//     for(int i = 1 ; i <= n/2 ; i++)
//     s += i * 2;

//     s+= n/2+1;

//   }
//   cout << s << endl;
}

void bal()
{
    int n, q;
    cin >> n >> q;
    int sum = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum = sum + v[i];
    }
    while (q--) {
        int x;
        cin >> x;
        int chdui = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int magi = sum - v[i] - v[j];
                magi = magi * 2;
                magi = magi + v[i] + v[j];
                if (magi == x) {
                    cout << v[i] << " ";
                    for (int k = 0; k < n; k++) {
                        if (k != i and k != j) {
                            cout << v[k] << " ";
                        }
                    }
                    cout << v[j] << endl;
                    chdui = 1;
                    break;
                }
            }
            if (chdui == 1) {
                break;
            }
        }
        if (chdui == 0) {
            cout << -1 << endl;
        }
    }
}

int main() {
  //  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


    int t;
    cin >> t;

    while (t--)
    {
        bal();


    }
    return 0;
}
