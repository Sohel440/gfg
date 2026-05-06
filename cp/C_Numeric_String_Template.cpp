
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
#define MYSELF_SOHEL_MOLLICK ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

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
template <typename T>struct Node {T data;Node *next;};
template <typename T> class List{private:Node<T> *head;public:List(){head = NULL; }void push(T val){Node<T> *n = new Node<T>();n->data = val;n->next = head;head = n;} T pop(){if(head) {T p = head->data;head = head->next;return p;}}bool search(T val) {Node<T> *temp = head;while(temp->next) { if(temp->data == val) return true;else temp = temp->next;}delete temp;return false;}};






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


int fun(int a , int b){
    if(a> b)return 1;
    else if(a == b) return 0;

    return -1;

}
string can_follow_recommendations(int n, vector<int>& a) {
    unordered_set<int> occupied;
    occupied.insert(a[0]);

    for (int i = 1; i < n; ++i) {
        if (occupied.count(a[i] - 1) || occupied.count(a[i] + 1)) {
            occupied.insert(a[i]);
        } else {
            return "NO";
        }
    }

    return "YES";
}

bool matches_template(const vector<int>& a, const string& s) {
    // First check: The lengths must be equal
    if (a.size() != s.size()) {
        return false;
    }
    
    unordered_map<int, char> num_to_char;
    unordered_map<char, int> char_to_num;

    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int num = a[i];
        char ch = s[i];
        
        // Check for consistent mapping
        if ((num_to_char.count(num) && num_to_char[num] != ch) ||
            (char_to_num.count(ch) && char_to_num[ch] != num)) {
            return false;
        }

        // Establish or verify the mappings
        num_to_char[num] = ch;
        char_to_num[ch] = num;
    }

    return true;
}

int32_t main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int m;
        cin >> m;
        while (m--) {
            string s;
            cin >> s;
            if (matches_template(a, s)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
