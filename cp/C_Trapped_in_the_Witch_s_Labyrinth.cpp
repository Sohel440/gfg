// //Let's start with the name of Allah
// //author : sohel440
// //I am use the template of sohel440
// //target to reach expert in @CF , 4* in @CC , knight in LC
// // try again and again until you win-----
// //-------------------------khuda Hafiz-----------------/

// #include<bits/stdc++.h>
// using namespace std;

// #define Amin() ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
// #define int long long int
// #define pb emplace_back
// #define all(x) x.begin(), x.end()
// #define rall(x) x.rbegin(), x.rend()
// #define forn(i, x, n) for (int i = x; i < n; i++)
// #define fore(i, x, n) for (int i = x; i <= n; i++)
// #define ref(i,x,n) for (int i = x ; i>=0 ; i--)
// #define debug printf("Sohel valo nei\n");
// #define vi(x) vector<x>
// #define el cout << endl;
// #define ff first 
// #define ss second 
// #define inp(a, n) forn(i,0,n) cin >> a[i]
// #define print(a,x,n) forn(i,x,n) cout <<a[i]<< " ";
// #define pair(x,y) pair<x,y> 
// #define mpq(x) priority_queue<x> 
// #define mxpq(x) priority_queue<x , vector<x> , greater<x> >
// #define mod 1000000007
// #define bit(x) __builin_popcountll(x)
// #define fbit(x) __builtin_clzll(x)
// #define PI 3.141592653589793238462




// void yes(){cout << "YES"<< endl;}
// void no(){cout << "No"<< endl;}


// /*****************************check ********************************/////
// bool isPrime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
// bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
// bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}return false;}

// /////************************************ Mathematical functions**************************////
// int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);} //
// int lcm(int a, int b){return (a/gcd(a,b)*b);}
// int moduloMultiplication(int a, int b, int p){int res = 0;a %= p;while(b) {if (b & 1)res = (res + a) % p;b >>= 1;}return res;}
// int powermod(int x, int y, int p){int res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}


// ////***********************bits****************/////
// int SetBit(int n, int X) { return n | (1 << X); }
// int ClearBit(int n, int X) { return n & ~(1 << X); }
// int ToggleBit(int n, int X) { return n ^ (1 << X); }
// bool CheckBit(int n, int X) { return (bool)(n & (1 << X));}
// string int_dec(int n) {return  bitset<32>(n).to_string();}


// template <typename V>void pop_front(V & v){assert(!v.empty());v.erase(v.begin());}
// /******************************main code*******************************/

// int N = 1e6;
// bool prime[1000007];
// void primeSive(){
//     memset(prime, true, sizeof(prime));
//     for (int p = 2; p * p <= N; p++) {
//         if (prime[p] == true) {
//             for (int i = p * p; i <= N; i += p) prime[i] = false;
//         }
//     }
// }






// void kaj(){

//     int n,m;
//     cin >> n >> m;

//     vi(string) a(n);
//     forn(i,0,n){
//         cin>>a[i];
//     }


//    vector<vi(int)> vis(1001 , vector<int> (1001,0));

//     queue<pair(int,int)>q;
    
//     for(int i =0 ; i < n ; i++){
//         if(a[i][0] == 'L'){
//             vis[i][0] = 1;
//             q.push({i ,0});
//         }
//         if(a[i][m-1] == 'R'){
//             vis[i][m-1]=1;
//             q.push({i, m-1});
//         }
//     }

//     forn(i, 0, m){
//         if(a[0][i] == 'U'){
//             vis[0][i] =1;
//             q.push({0, i});
//         }
//         if(a[n-1][i] == 'D'){
//             q.push({n-1 ,i});vis[n-1][i]=1;
//         }
//     }


//     while(!q.empty()){

//         auto tt = q.front();
//         q.pop();

//         int i = tt.ff;
//         int j = tt.ss;

//         if(i > 0 && vis[i-1][j]==0 && a[i-1][j] == 'D'){
//             vis[i-1][j]=1;
//             q.push({i-1, j});
//         }
//         if( j > 0 && vis[i][j-1] == 0 && a[i][j-1] == 'R'){
//             q.push({i, j-1});
//             vis[i][j-1]=1;
//         }

//         if(i <n-1 && vis[i+1][j]== 0 && a[i+1][j] == 'U'){
//             q.push({i+1,j}); vis[i+1][j]=1;
            
//         }
//         if(j <m-1 && vis[i][j+1]== 0 && a[i][j+1] == 'L'){
//             q.push({i,j+1}); vis[i][j+1]=1;

//         }
//     }

//     int ans=0;
//     for(int i = 0; i <  n ;i++){
//         for(int j = 0 ;j < m ; j++){
//             if(vis[i][j] == 0 && a[i][j] != '?')ans++;
//             else if(vis[i][j]==0){
//                 bool ok = true;
//                 if(i>0) ok &=vis[i-1][j];
//                 if(j >0) ok &=vis[i][j-1];
//                 if(j < n-1) ok&=vis[i+1][j];
//                 if(j < m-1) ok&=vis[i][j+1];

//                 if(ok==0)ans++;
//             }
//         }
//     }
//     cout << ans << endl;

// }
// signed main(){

//     Amin();
//     int t=1;
//     cin >> t;
//     while(t--){
//         kaj();
//     }
// }
// //-------------------------khuda Hafiz-----------------/

#include <bits/stdc++.h>
using namespace std;

bool bad[1001][1001];
string s[1001];

void solve()
{

    int n, m;
    cin >> n >> m;

    // Initialize bad array
     for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) { bad[i][j] = 0; } }

    // Read the grid
     for (int i = 0; i < n; ++i) { cin >> s[i]; }
     queue<pair<int, int>> q;

// Mark boundaries with bad cells

     for (int i = 0; i < n; ++i)
     {
         if (s[i][0] ==  'L')
             bad[i][0] = 1; q.push({i, 0}); 

             if ( s[i][m - 1] =='R'){
                 bad[i][m-1] = 1; q.push({i, m-1}); 
             }

    }
     for (int i = 0; i < m; ++i){
         if (s[0][i] == 'U')
         {
             q.push({0, 1});
             bad[0][i] = 1;
         }
     if (s[n - 1][i] == 'D')
         q.push({n - 1, i});
     bad[n - 1][i] = 1;
}

while (!q.empty())
{
    auto cur = q.front();
    q.pop();

    int x = cur.first, y = cur.second;

    if (x > 0 && bad[x - 1][y] == 0 && s[x - 1][y] == 'D')
    {
        bad[x - 1][y] = 1;
        q.push({x - 1, y});
        
    }
    if (x < n - 1 && bad[x + 1][y] == 0 && s[x + 1][y] == 'U')
    {
        bad[x + 1][y] = 1;
        q.push({x + 1, y});
    }
    if (y > 0 && bad[x][y - 1] == 0 && s[x][y - 1] == 'R')
    {
        bad[x][y - 1] = 1;
        q.push({x, y - 1});
    }
    if (y < m - 1 && bad[x][y + 1] == 0 && s[x][y + 1] == 'L')
    {
        bad[x][y + 1] = 1;
        q.push({x, y + 1});
    }
}

int ans = 0;

ans++;

for (int i = 0; i < n; ++i)
{
    for (int j = 0; j < m; ++j)
    {
        if (bad[i][j] == 0 && s[i][j] != '?')
        {
        }
        else if (bad[i][j] == 0)
        {
            bool flag = 1;
            if (i > 0)
                flag &= bad[i - 1][j];
            if (i > 0)
                flag &= bad[i][j - 1];
            if (i < n - 1)
                flag &= bad[i + 1][j];
            if (m - 1)
                flag &= bad[i][j + 1];

            if (flag == 0)
                ans++;
        }

       
    }
}

 cout << ans << endl;
}

int main()
{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {

        solve();
    }

    return 0;
}