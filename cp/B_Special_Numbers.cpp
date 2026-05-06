/*  */
    
// sohel440
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
 


/**********direction*******/
int row[] = {1, 0, -1, 0};
int col[] = {0, 1, 0, -1};
const int mod = 1e9 + 7;




int count(const string& str, const string& sub) {
    int count = 0;
    size_t pos = str.find(sub); // Find the first occurrence of the substring
    while (pos != string::npos) { // While substring is found
        count++; // Increment the count
        pos = str.find(sub, pos + sub.size()); // Find the next occurrence starting from the end of the previous one
    }
    return count;
}

bool compare(string &a , string &b){
    int i =0;
    int j = a.size()-1;
    while(i<=j){
        if(a[i] < a[j]){
            return true;
        }else if(a[i] > a[j]){
            return false;
        }else{
            i++;
            j--;

        }
    }
    return true;
    
}

int dp_tei_korbo(int ind, int n, vector<int> &a, vector<vector<int>> &memo) {
    if (n == 0) return 0;
    if (ind >= a.size()) return 0;
    if (memo[ind][n] != -1) return memo[ind][n];
  // nilam na 
    int nontake = dp_tei_korbo(ind + 1, n, a, memo);
    //nilam 
    int take = (n >= a[ind]) ? 1 + dp_tei_korbo(ind, n - a[ind], a, memo) : INT_MAX;

    return memo[ind][n] = min(take, nontake);
}
int bottom_up(int n){
       vector<int> coins = {1, 3, 6, 10, 15};
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[n];
}

void kaj() {

    int n , k;
    cin >> n >> k;

    int ans =0;
    int p = 1;

    forn(i , 0 , 32){
        
        if((1 << i) & k){
            ans += p;
            ans = ans % mod;

        }

        p = p * n;
        p = p % mod;
    }


    cout << ans << endl;

  

}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        kaj();


 

    return 0;
   
}

