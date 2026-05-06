//Let's start with the name of Allah
//author : sohel440
//I am use the template of sohel440
//target to reach expert in @CF , 4* in @CC , knight in LC
// try again and again until you win-----
//-------------------------khuda Hafiz-----------------/

#include<bits/stdc++.h>
using namespace std;

#define Amin()       ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
#define ll          long long int
#define b            emplace_back
#define all(x)       x.begin(), x.end()
#define rall(x)      x.rbegin(), x.rend()
#define forn(i, x, n) for (ll i = x; i < n; i++)
#define fore(i, x, n) for (ll i = x; i <= n; i++)
#define ref(i,x,n)   for (ll i = x ; i>=0 ; i--)
#define debug        printf("Sohel valo nei\n");
#define vi(x)        vector<x>
#define el           cout << endl;
#define ff           first 
#define ss           second 
#define inp(a, n)    forn(i,0,n) cin >> a[i]
#define print(a,x,n) forn(i,x,n) cout <<a[i]<< " ";
#define pair(x,y)    pair<x,y> 
#define mpq(x)       priority_queue<x> 
#define mnpq(x)      priority_queue<x , vector<x> , greater<x> >
#define m            1000000007
#define bit(x)       __builin_popcountll(x)
#define fbit(x)      __builtin_clzll(x)
#define PI           3.141592653589793238462




void yes(){cout << "YES"<< endl;}
 void no(){cout << "No"<< endl;}


/*****************************check ********************************/////
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(ll n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

/////************************************ Mathematical functions**************************////
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a, ll b, ll p){ll res = 0;a %= p;while(b) {if (b & 1)res = (res + a) % p;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}


////***********************bits****************/////
ll SetBit(ll n, ll X) { return n | (1 << X); }
ll ClearBit(ll n, ll X) { return n & ~(1 << X); }
ll ToggleBit(ll n, ll X) { return n ^ (1 << X); }
bool CheckBit(ll n, ll X) { return (bool)(n & (1 << X));}
string ll_dec(ll n) {return  bitset<32>(n).to_string();}


template <typename V>void pop_front(V & v){assert(!v.empty());v.erase(v.begin());}
/******************************main code*******************************/

ll N = 1e6;
bool prime[1000007];
void primeSive(){
    memset(prime, true, sizeof(prime));
    for (ll p = 2; p * p <= N; p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i <= N; i += p) prime[i] = false;
        }
    }
}




void kaj(){

    ll n , q , l;
    cin >> n >> q >> l;

    vi(pair(int,int)) a(n), b(q);
    forn(i,0,n){
        cin >> a[i].ff >> a[i].ss;
    }
    forn(i,0,q){
        cin>> b[i].ff>> b[i].ss;
    }
    // forn(i,0,n) cout << a[i].ff<< " "<< a[i].ss<<endl;
    // el;
    // forn(i,0,q) cout << b[i].ff<< " "<< b[i].ss<<endl;
    // el;

    mpq(ll) pq;// priority_queue
    ll  have =1;
    ll  u =0;
    ll ans=0;

    sort(all(a));
    forn(i,0,n){

        ll len  = a[i].ss - a[i].ff+2;
        while(u < q && b[u].ff < a[i].ff){
            
            pq.push(b[u].ss); 
            u++;
        }


        while(!pq.empty() && have < len){
            // cout << pq.top()<< endl;
            have += pq.top();
            pq.pop();
            ans++;
        }

        if(have < len){
            cout << -1 << endl;
            return;

        }
    }

    cout << ans << endl;


}
signed main(){

    Amin();
    ll t=1;
    cin >> t;
    while(t--){
        kaj();
    }
}
//-------------------------khuda Hafiz-----------------/