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
class STree {
private:
    vector<map<int, int>> distinctTree; // Segment tree to store frequency maps
    int n;

    // Function to merge two frequency maps
    map<int, int> mergeMaps(const map<int, int>& left, const map<int, int>& right) {
        map<int, int> result = left;
        for (const auto& it : right) {
            result[it.first] += it.second;
        }
        return result;
    }

    // Function to build the segment tree
    void buildTree(vector<int>& a, int tl, int tr, int v = 1) {
        if (tl == tr) {
            distinctTree[v][a[tl]]++; // Increment the frequency of the element
            return;
        }

        int tm = (tl + tr) / 2;
        buildTree(a, tl, tm, v*2);
        buildTree(a, tm+1, tr, v*2+1);

        // Merge the two child nodes to form the parent node
        distinctTree[v] = mergeMaps(distinctTree[v*2], distinctTree[v*2+1]);
    }

    // Helper function to get the frequency map for a given range
    map<int, int> getDistinctMap(int v, int tl, int tr, int l, int r) {
        if (l > r) return map<int, int>(); // Invalid range
        if (l <= tl && r >= tr) {
            return distinctTree[v]; // Complete overlap, return the map
        }

        int tm = (tl + tr) / 2;
        map<int, int> leftMap = getDistinctMap(v*2, tl, tm, l, min(r, tm));
        map<int, int> rightMap = getDistinctMap(v*2+1, tm+1, tr, max(l, tm+1), r);

        return mergeMaps(leftMap, rightMap); // Return the merged map
    }

public:
    // Constructor to initialize the segment tree
    STree(int sz, vector<int>& vec) {
        n = sz;
        distinctTree.resize(sz * 4);
        buildTree(vec, 0, n-1);
    }

    // Function to get the number of distinct elements in range [l, r]
    int getDistinct(int l, int r) {
        map<int, int> distinctMap = getDistinctMap(1, 0, n-1, l, r);
        return distinctMap.size(); // Return the count of distinct elements
    }

    // Function to get the distinct elements as a set
    set<int> getDistinctSet(int l, int r) {
        map<int, int> distinctMap = getDistinctMap(1, 0, n-1, l, r);
        set<int> distinctSet;
        for (const auto& it : distinctMap) {
            distinctSet.insert(it.first);
        }
        return distinctSet; // Return the set of distinct elements
    }
};

// Function to combine results from two ranges in two different arrays
int getCombinedDistinct(STree& tree1, STree& tree2, int a, int b, int c, int d) {
    set<int> distinctSet1 = tree1.getDistinctSet(a, b);
    set<int> distinctSet2 = tree2.getDistinctSet(c, d);

    // Merge the two sets
    set<int> combinedSet;
    combinedSet.insert(distinctSet1.begin(), distinctSet1.end());
    combinedSet.insert(distinctSet2.begin(), distinctSet2.end());

    return combinedSet.size(); // Return the number of distinct elements
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

void kaj() {
    
    int n;
    cin >> n;
    vi a(n) , b(n);
    inp(a, n); inp(b , n);

    STree st(n,a);
    STree st1(n , b);

    int q;
    cin >> q;

    while(q--){
        int a , b , c , d;
        cin >> a >> b >> c >> d;

        cout << getCombinedDistinct(st , st1, a-1 , b-1 , c-1, d-1)<< endl;;
    }
   


}


int32_t main() {
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    int t;
//    cin >> t;
//    while (t--)
        kaj();

    return 0;
}