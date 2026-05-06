//Let's start with the name of Allah
//sohel440
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define forn(i, x, n) for (int i = x; i < n; i++)
#define fore(i, x, n) for (int i = x; i <= n; i++)
#define vi vector<int>
#define vpp vector<pair<int, int>>
#define vs vector<string>
#define vll vector<long long>
#define in(x) scanf("%d", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define nl printf("\n")
#define inp(a, n) forn(i,0,n) cin >> a[i]
void yes(){cout << "YES"<< endl;};
void no(){cout << "NO"<< endl;};
/*********************************kadane alogo ***********************///////
int kdn(vi &a, int n){int mx = 0, sum = 0;forn(i, 0, n) {sum += a[i];if (sum < 0)sum = 0;mx = max(mx, sum);}return sum;}


// *****************************check ********************************/////
bool isPrime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}return false;}


/////************************************ Mathematical functions**************************////
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);} //
int lcm(int a, int b){return (a/gcd(a,b)*b);}
int moduloMultiplication(int a,int b,int mod){int res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
int powermod(int x, int y, int p){int res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}



////***********************bits****************/////
int SetBit(int n, int X) { return n | (1 << X); }
int ClearBit(int n, int X) { return n & ~(1 << X); }
int ToggleBit(int n, int X) { return n ^ (1 << X); }
bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
int binaryToDecimal(string n){string num = n;int dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
 
template <typename V>
void pop_front(V & v)
{
    assert(!v.empty());
    v.erase(v.begin());
}

template <typename T>
void input(T& arr) {
    for (auto& element : arr) {
        cin >> element;
    }
}


template<typename T>
void printArray(T &arr){
    for(auto tt: arr){
        cout << tt<< " ";
    }
    cout << endl;
}

int maxDivisor(int N) {
    int maxDiv = 1;
    for (int i = 1; i <= sqrt(N); ++i) {
        if (N % i == 0) {
            if (i != N) {
                maxDiv = max(maxDiv, i);
            }
            if (i != N / i && N / i != N) {
                maxDiv = max(maxDiv, N / i);
            }
        }
    }
    return maxDiv;
}
 const int N = 1000000;
bool prime[N + 1];
void primeSive(){
    
    
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= N; p++) {
        if (prime[p] == true) {

            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}

/*******************************binary search *********************************************/
bool search(vi &x, int n, int k) {
    int l = 0, r = n-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (x[m] == k) return true;
        if (x[m] < k) l = m+1; else r = m-1;
    }
    return false;
}
int search_Ind(vi &x, int n, int k) {
    int l = 0, r = n-1;
    int ans=-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (x[m] == k) {ans = m ; r =m-1;}
        if (x[m] < k) l = m+1; else r = m-1;
    }
    return ans;
}

vi copy(int x , vi &a){
    vi ans;
    for(int i = 0; i < a.size(); i++){
        if(i!=x){
            ans.push_back(a[i]);
        }
    }
    return ans;
}

void kaj() {
   
   int n;
   cin >> n;

   vi a(n);
   inp(a ,n);

   vi b;
   int prev =-1;
   int i =0;
   for( i = 0 ; i < n-1 ; i++){
      int val = __gcd(a[i], a[i+1]);
      if(val < prev){
       break;
      }

      prev = val;
      b.pb(val);
   }
   int pp = i-1;
   int curr = i;
   int next = i+1;
   vi p1 = copy(i -1 , a);
   vi p2 =copy(i , a);
   vi p3 = copy(i+1 , a);

   bool ok = true;
   prev=-1;
   for(int i = 0 ; i < p1.size()-1; i++){
       int val = gcd(p1[i], p1[i+1]);
       if(val <prev){
         ok = false;
         break;
       }
       prev = val;
   }

   if(ok){yes(); return;}
   ok =true;
   prev =-1;
   for(int i = 0 ; i < p2.size()-1; i++){
       int val = gcd(p2[i], p2[i+1]);
       if(val <prev){
         ok = false;
         break;
       }
       prev = val;
   }
    if(ok){yes(); return;}
   ok =true;
   prev =-1;
   for(int i = 0 ; i < p3.size()-1; i++){
       int val = gcd(p3[i], p3[i+1]);
       if(val <prev){
         ok = false;
         break;
       }
       prev = val;
   }
   if(ok)yes();
   else no();
   
//    printArray(p1);
//    printArray(p2);
//    printArray(p3);



    
}


int32_t main() {
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int t;
   cin >> t;
   while (t--)
        kaj();

    return 0;
}