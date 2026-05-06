// #include <iostream>
// #include <vector>
// using namespace std;

// void zigzag(vector<int>& A, int start, int direction) {
//     int N = A.size();
//     int pos = start;
    
//     while (pos >= 0 && pos < N) {
//         if (A[pos] > 0) {
//             A[pos]--;
//             direction = -direction;
//         }
//         pos += direction;
//     }
// }



// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         int N;
//         cin >> N;
//         vector<int> A(N);
//         for (int i = 0; i < N; ++i) {
//             cin >> A[i];
//         }
        
//         int ways = 0;
//         for (int i = 0; i < N; ++i) {
//             if (A[i] == 0) {
//                 vector<int> A_copy = A;
//                 simulate(A_copy, i, 1); // Push to the right
//                 if (allWallsDestroyed(A_copy)) {
//                     ways++;
//                 }
                
//                 A_copy = A;
//                 simulate(A_copy, i, -1); // Push to the left
//                 if (allWallsDestroyed(A_copy)) {
//                     ways++;
//                 }
//             }
//         }
        
//         cout << ways << endl;
//     }
    
//     return 0;
// }




// DATE : 7 / 8 / 2024

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
#define MYSELF_MOLLICK ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

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

void zigzag(vi & a, int s, int dir) {
    int N = a.size();
    int i = s;
    
    while (i >= 0 && i < N) {
        if (a[i] > 0) {
            a[i]--;
            dir = -dir;
        }
        i += dir;
    }
}
 bool check(const vi & a) {
    for (int hi : a) {
        if (hi > 0) {
            return false;
        }
    }
    return true;
}

vi ans;
void kaj() {
        int N;  // Size of the array
        cin >> N;
        vector<int> A(N);  // The array elements

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        vector<int> psum(N, 0);  
        vector<int> ssum(N, 0); 

        
        psum[0] = A[0];
        for (int i = 1; i < N; ++i) {
            psum[i] = psum[i - 1] + A[i];
        }

        // Compute suffix sums
        ssum[N - 1] = A[N - 1];
        for (int i = N - 2; i >= 0; --i) {
            ssum[i] = ssum[i + 1] + A[i];
        }

        int ways = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] == 0) {
                if (ssum[i] == psum[i]) {
                    ways += 2;
                } else if (abs(ssum[i] - psum[i]) == 1) {
                    ways += 1;
                }
            }
        }

        ans.push_back(ways);

}


int32_t main() {
    MYSELF_MOLLICK;

   int t;
   cin >> t;
   while (t--)
        kaj();

        forn(i , 0 , ans.size()){
            cout << ans[i]<< endl;
        }

    return 0;
}