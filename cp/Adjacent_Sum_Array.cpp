//Let's start with the name of Allah
//author : sohel440
//I am use the template of sohel440
//target to reach expert in @CF , 4* in @CC , knight in LC
// try again and again until you win-----
//-------------------------khuda Hafiz-----------------/

#include<bits/stdc++.h>
using namespace std;

#define Amin() ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
#define int long long int
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define forn(i, x, n) for (int i = x; i < n; i++)
#define fore(i, x, n) for (int i = x; i <= n; i++)
#define ref(i,x,n) for (int i = x ; i>=0 ; i--)
#define debug printf("Sohel valo nei\n");
#define vi(x) vector<x>
#define el cout << endl;
#define ff first 
#define ss second 
#define inp(a, n) forn(i,0,n) cin >> a[i]
#define print(a,x,n) forn(i,x,n) cout <<a[i]<< " ";
#define pair(x,y) pair<x,y> 
#define mpq(x) priority_queue<x> 
#define mxpq(x) priority_queue<x , vector<x> , greater<x> >
#define m 1000000007
#define bit(x) __builin_popcountll(x)
#define fbit(x) __builtin_clzll(x)
#define PI 3.141592653589793238462




void yes(){cout << "YES"<< endl;}
void no(){cout << "No"<< endl;}


/*****************************check ********************************/////
bool isPrime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}return false;}

/////************************************ Mathematical functions**************************////
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);} //
int lcm(int a, int b){return (a/gcd(a,b)*b);}
int moduloMultiplication(int a, int b, int p){int res = 0;a %= p;while(b) {if (b & 1)res = (res + a) % p;b >>= 1;}return res;}
int powermod(int x, int y, int p){int res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}


////***********************bits****************/////
int SetBit(int n, int X) { return n | (1 << X); }
int ClearBit(int n, int X) { return n & ~(1 << X); }
int ToggleBit(int n, int X) { return n ^ (1 << X); }
bool CheckBit(int n, int X) { return (bool)(n & (1 << X));}
string int_dec(int n) {return  bitset<32>(n).to_string();}


template <typename V>void pop_front(V & v){assert(!v.empty());v.erase(v.begin());}
/******************************main code*******************************/

int N = 1e6;
bool prime[1000007];
void primeSive(){
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= N; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= N; i += p) prime[i] = false;
        }
    }
}




void kaj(){

    int n ;
    cin>>n;
    

    vector<int> a(n-1);
    for(int i = 0 ; i < n-1 ; i++){
        cin>> a[i];
    }

    vi(int) b ;
    sort(all(a));

    b.push_back(a[0]/2);
    b.push_back(a[0]/2+(a[0]%2==1));

    for(int i = 1 ; i < a.size(); i++){
        int val = a[i]- b.back();
        b.push_back(val);

    }

    print(b , 0, n);el;



    

  

}
signed main(){

    Amin();
    int t=1;
    cin >> t;
    while(t--){
        kaj();
    }
}
//-------------------------khuda Hafiz-----------------/
