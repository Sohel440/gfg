// rating 2243
// https://www.codechef.com/START134B




/**
        /*author: Sohel Mollick;
email  :sbnammallick@gmail.com

*/

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
#define inp(x, n) for(int i = 0; i < n; ++i) std::cin >> x[i]

/*********************************kadane alogo ***********************///////
int kdn(vi &a, int n){int mx = 0, sohel = 0;forn(i, 0, n) {sohel += a[i];if (sohel < 0)sohel = 0;mx = max(mx, sohel);}return sohel;}


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
const int INF= LONG_LONG_MAX;



int count(const string& str, const string& sub) {
    int count = 0;
    size_t pos = str.find(sub); // Find the first occurrence of the substring
    while (pos != string::npos) { // While substring is found
        count++; // Increment the count
        pos = str.find(sub, pos + sub.size()); // Find the next occurrence starting from the end of the previous one
    }
    return count;
}


int dpTeikorbo(int n , vector<int> &dp){
    if(n <=1) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = ((dpTeikorbo(n-1 , dp)) %mod + (((((n-1 ) %mod * (dpTeikorbo(n-2 , dp) )%mod) * 2) %mod)%mod) %mod)%mod;
    return dp[n];


}

bool fun(vector<string> &grid , int n , int m ,char ch ){
    bool ok = false;
     
    for(int i = 0 ;  i < n ; i++){
        if(grid[i][0] == ch){
            ok = true;
            break;
        }
    }

    if(ok == false) return false;
    ok = false;
    for(int i = 0 ;  i < n ; i++){
        if(grid[i][m-1] == ch){
            ok = true;
            break;
        }
    }

    if(ok == false) return false;
    ok = false;
    for(int i = 0 ;  i < m ; i++){
        if(grid[0][i] == ch){
            ok = true;
            break;
        }
    }

    if(ok == false) return false;
    ok = false;
    for(int i = 0 ;  i < m ; i++){
        if(grid[n-1][i] == ch){
            ok = true;
            break;
        }
    }

    if(ok == false) return false;

    return true;
    

}

const int bits =30;
const int N =200003;
int pref[N][bits];
int a[N];


vi bhagfol (int k){
    vector<int> ans;
    for(int i =2 ; i * i <= k ;i++){
        while(k %i ==0){
            k = k /i;
            ans.push_back(i);

        }
    }

    if(k > 1){
        ans.pb(k);
    }
    return ans;
}

void kaj() {
 int n,k,q;
	cin>>n>>k>>q;
	
	int a[k+1], b[k+1]; 
	a[0]=0; b[0]=0;
	
	for(int i=1;i<=k;i++){
	    cin>>a[i];
	}
	for(int i=1;i<=k;i++){
	    cin>>b[i];
	}
	
	while(q--){
	    
	    int d;
	    cin>>d;
	    
	    if(d==0){cout<<0<<" "; continue;}
	    if(d==n){cout<<b[k]<<" "; continue;}
 
	    int ind = upper_bound(a,a+k+1,d) - a;
	    int ans = b[ind-1]; //time taken to the reach the stop just before distance d
	    
	    int dist = a[ind] - a[ind-1];
	    int time_taken = b[ind] - b[ind-1] ;
	    
	    // time_to_cover_unit_dist = time_taken/dist;
	    
	    int extra_dist_to_cover = d-a[ind-1];
	    int extra_time = (extra_dist_to_cover*time_taken)/(dist);//ans
	    ans+=extra_time;
	    
	    cout<<ans<<" ";
    }
    cout << endl;


} 
  


int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        kaj();

    return 0;
}



