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
    
    int n , m , k;
    cin >> n>> m >> k;
  
    vector<int> a(n), b(m);

    forn(i, 0,n) cin >> a[i];
    forn(i, 0, m) cin >> b[i];
     
    


    sort(all(a));
    sort(all(b));

    

    if(k % 2 ==0){
      

        if(a[0] < b[m-1]){
            swap(a[0], b[m-1]);
            sort(all(a));
            sort(all(b));

        }

        if(b[0] < a[n-1]){
            swap(a[n-1], b[0]);
             sort(all(a));
            sort(all(b));
        }
        
        

    }
    else{

         if(a[0] < b[m-1]){
            swap(a[0], b[m-1]);
            sort(all(a));
            sort(all(b));

        }
        
    }

       int s =0;
        forn(i, 0 , n) s += a[i];


        cout << s << endl;

     
} 

int32_t main() {
    int t;
    cin >> t;
    while(t--) 
        kaj();


    return 0;
}
