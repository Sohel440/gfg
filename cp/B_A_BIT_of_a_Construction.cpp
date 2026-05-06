
// C. Grouping Increases
// author : Sohel Mollick;
// email  :sbnammallick@gmail.com
// time   : 12:35 pm : Saturday, 20 April 2024 (IST)

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


void kaj() {

  
   int n, k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << k << endl;
        return;
    }
  
    int sohel = log2(k);
    int first = 1 << sohel;

    cout << (first - 1) << " ";
    cout << (k - (first - 1)) << " ";
    for (int i = 2; i < n; i++)
    {
        cout << "0 ";
    }
    cout << endl;

   
//    if(n==1){
//             cout<<k<<endl;
//             return;

//         }
     
//             int sohel=0;
//             if(k+1==(1<<((int)log2(k)))){
//                 cout<<k<<" "; // if not power of 2 
//                 // chal ho gaya 
//             }
//             else{
//                 cout<<(1<<(int)log2(k))-1<<" "; // if even
//                 sohel=k-((1<<(int)log2(k))-1);
//             }


//             for(int i=0; i<(n-1); i++){
//                 cout<<sohel<<" ";
//                 sohel=0;
//             }
//             cout<<endl;

}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        kaj();

    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;
 
// #define int long long
// #define pi 3.14159265359
// #define endl "\n"


// string fun(int n)
// {
//   string s="";
//   while(n>0)
//   {
//     if(n%2==0)s=s+'0';
//     else s=s+'1';
//     n=n/2;
//   }
//   return s;
// }


// void solve()
// {
//   vector<int>ans;
//   int n,k; cin>>n>>k;
//   string s=fun(k);
//   map<int,int>mp;
//   int c=0;int n1=n;
//   for(int i=0;i<s.length();i++)
//   {
//     if(s[i]=='1')c++;
//   }
//   int l=s.length();
//     for(int i=0;i<l;i++)
//     {
//       if(n==1)
//       {
//         int x=0;
//         while(i<l)
//         {
//           if(s[i]=='1')x=x+pow(2,i);
//           i++;
//         }
//         ans.push_back(x);
//         n--;
//       }
//       else
//       {
//         int k=pow(2,i);
//         if(s[i]=='1')
//         {
//           ans.push_back(k); n--;
//         }
//       }
//       if(n==0)break;
//     }
   
//    while(n>0)
//    {
//     ans.push_back(0);
//     n--;
//    }

//   for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
//   cout<<endl;

// }  
 
// signed main()
// {
//    ios_base::sync_with_stdio(0); cin.tie(0);
//    int t; cin>>t;
//    while(t--)
//   solve();
// }