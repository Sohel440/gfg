/***

            Bismillahir Rahmanir Rahim
            Read in the name of Allah, who created you!!!
            Author : Sohel mointck
            Department of CSE, RKMGEC (WBUT), INDIA.

***/

#include <bits/stdc++.h>
using namespace std;

#define             jeno_joyer_khida_thake      int main (void)
#define             kaj_shesh                   return 0
#define             sf(x)                          scanf ("%d", x)         
#define             pf(x)                       cout << x
#define             ssf                         sscanf
#define             spf                         sprintf
#define             fsf                         fscanf
#define             fpf                         fprintf
#define             fast                        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define             scase                       sf ("%d",&tc)
#define             whilecase                   while (tc--)
#define             sn                          sf ("%d",&n)
#define             eof                         while (cin >> n)
#define             pcase                       pf ("Case %d: ",pos)
#define             llu                         unsigned long long
#define             lld                         long long int 
#define             U                           unsigned int
#define             for0(i,n)                   for (i=0; i<n; i++)
#define             for1(i,n)                   for (i=1; i<=n; i++)
#define             forab(i,a,b)                for (i=a; i<=b; i++)
#define             rof0(i,n)                   for (i=n-1; i>=0; i--)
#define             rof1(i,n)                   for (i=n; i>=1; i--)
#define             rofab(i,a,b)                for (i=b; i>=a; i--)
#define             c(str)                      cin >> str
#define             g(str)                     	getline (cin,str)
#define             vi                          vector <int>
#define             vlld                        vector <lld>
#define             si                          set <int>
#define             slld                        set <lld>
#define             ss                          set <string>
#define             vs                          vector <string>
#define             pii                         pair <int,int>
#define             mii                         map <int,int>
#define             msi                         map <string,int>
#define             pb                          push_back
#define             in                          insert
#define             B                           begin()
#define             E                           end()
#define             rB                          rbegin()
#define             rE                          rend()
#define             F                           first
#define             S                           second
#define             iterate(it,x)               for (it=x.B; it!=x.E; it++)
#define             riterate(rit,x)             for (it=x.rB; it!=x.rE; it++)
#define             sort(x)            	        sort (x.B,x.E)
#define             sortR(x,a,b)            	sort (x.B+a,x.B+b+1)
#define             rev(x)                  	reverse (x.B,x.E)
#define             revR(x,a,b)             	reverse (x.B+a,x.B+b+1)
#define             cl(x)                       x.clear()
#define             end1                        "\n"

const int MOD = 1000000007;
const int MAX = 1000005;
const double PI = acos(-1.0);

int SetBit (int n, int X) { return n | (1 << X); }
int ClearBit (int n, int X) { return n & ~(1 << X); }
int ToggleBit (int n, int X) { return n ^ (1 << X); }
bool CheckBit (int n, int X) { return (bool)(n & (1 << X)); }

long long int  moduo_korlam(int a , int b){
    
    long long int res = 1;

    while( b > 0 ){

        if(b & 1){
            res = res * a;

        }
        a = a*a;

        b = b>> 1;

    }
    return res;

}
int x , y;

void extend_kaj(int a , int b){

if(b == 0){
    x = 1;
    y =0;
    return;
}

extend_kaj(b , a%b);

int cx = y;
int cy = x - (a/b)*y;

x = cx;
y = cy;



}
int modular_multi(int a , int b , int n){

    int res =0;
    while(b){

        if(b & 1ll){
            res = (res +a);

        }
        res = res %n;
        b /= 2;
        a *= 2;
        a %= n;

       

    }

    return res;

}
lld  inv (lld base , lld p , lld m){
    lld res = 1;
    while(p){
        if(p&1ll){
          
          res = modular_multi(res , base , m);
          
        }
        base = modular_multi(base , base , m);
        base = base % m;
        p /= 2;


    }
    return res;

}
int extendedGCD(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedGCD(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedGCD(a, m, x, y);
    if (gcd != 1) {
        // Modular inverse does not exist
        return -1;
    }
    return (x % m + m) % m;
}





const int N = 100005;
int prime_count[N];
int mobius[N];


int a[N];

void solve(){

    lld n ,p;
   cin >> n >> p;;
   if(n >= p) {cout << 0 << endl; return ;}
    lld ans = -1;

    for (lld i = (n+ 1) ; i <= (p-1) ; i++){
        int t = inv(i, p-2 , p);
        ans =( t * ans) %p;
    }

    cout <<  ans+p << endl;;

}
jeno_joyer_khida_thake 
{
    /*
		freopen ("input.txt","r",stdin);
		freopen ("output.txt","w",stdout);
    */
   
   int t;
   cin >> t;
   while(t--){

    solve();
   }


     


    kaj_shesh;
}