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
#define mod 1000000007
#define sz size()
#define bit(x) __builin_popcountll(x)
#define fbit(x) __builtin_clzll(x)
#define PI 3.141592653589793238462




void yes(){cout << "YES"<< endl;}
void no(){cout << "NO"<< endl;}


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

int modular_exp(int x, int y, int m)
{
    int ans = 1;
    while(y > 0)
    {
        if(y & 1) ans = (ans * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return ans;
}

int mod_inv(int x , int m){
    return modular_exp(x , m-2 , m);

}
void kaj(){

    string s;
    cin>> s;
    int n = s.sz;

    int c2 =0 ;int c3 =0;
    int sum =0;
    forn(i,0,n){
        if(s[i]=='2')c2++;
        else if(s[i] == '3')c3++;
        sum += s[i]-'0';
    }


    int diff = ((9  - sum % 9)%9);
    forn(b,0, c3+1){

        int diff1 = (diff - (6LL * b))%9;
        if(diff1 < 0)diff1 += 9;
        int mm =9;
        int two = (diff1 * 5 ) % 9 ;//* mod_inv(2 , mm) % 9;
        if(two <= c2){
            yes();
            return;
        }
    }
    no();


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


// requires Flcs
// \FOR START CODE
// init -> Initialize C++ Main()
// init-cp -> CP-Initialize C++ Main()
// FOR TESTCASES
// tw -> While-TestCase
// tf -> For-TestCase
// twsv -> While-TestCase with Special Value
// tweof -> While-TestCase with EOF
// FOR VECTOR
// prnt_vec -> Print Vector
// vec -> Initialize Vector
// FOR ARRAY
// prnt_Farr -> Initialize Function For Printing 1D Array
// prnt_arr -> Print Array
// arr -> Initialize Array[size] With Input
// arr_2d -> Initialize 2D Array
// prnt_arr_2d -> Print 2D Array
// FOR BASIC I/O
// print -> Print COUT
// scan -> Get CIN
// FOR GENERATING
// gen_Fprime -> Generate Prime Numbers Till N

// gen_prime -> (vector) Initialize Prime Numbers Generator

// gen_Fprimefactors -> (vector) Generates Prime Factors Function

// gen_primefactors -> (vector) Initialize Prime Factors

// FOR CONVERSION
// conv_inttobits -> Convert Int To Binary

// conv_Fnumtostr -> (string) Convert Number to String Function

// conv_numtostr -> (string) Convert Number to String

// conv_Fstrtonum -> (ll) Convert String to Number Function

// conv_strtonum -> (ll) Convert String to Number

// FOR ALGORITHMS
// Fbs -> (vec,ll) Returns Index using Binary Search Function

// bs -> (vec,ll) Returns Index using Binary Search

// Fprime -> (ll) Returns 1 or 0 if Prime or Not

// prime -> Initialize Prime Checker Variable

// Fdfs -> DFS Function

// dfs -> Initializes DFS

// Fbfs -> BFS Function (bfs_nodes)

// bfs -> (root,edge) BFS Initialize (bfs_nodes)

// Fgcd -> GCD Function

// gcd -> (ll) Returns GCD

// Flcm -> (ll) LCM Function

// lcm -> (ll) Returns the LCM Number

// Fpower -> (base^upper) Power Function

// power -> Do Power (base^powervar)

// Flcs -> Longest Common Subsequence Length Function

// lcs -> Longest Common Subsequence Length Between two strings

// Fbe -> Binary Exponent Function

// be -> Initialize Binary Exponent Function

// Fme -> Modular Exponentiation Function

// me -> Initilaize Modular Exponentiation Function

// Data Structures
// olist -> Initialize Ordered List

// requires Fme

// requires Fbe
// requires Fbs

// requires Fprime
// requires conv_Fnumtostr