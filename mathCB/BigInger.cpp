/***

            Bismillahir Rahmanir Rahim
            Read in the name of Allah, who created you!!!
            Author : Sohel mollick
            Department of CSE, RKMGEC (WBUT), INDIA.

***/

#include <bits/stdc++.h>
using namespace std;

#define             Bishmillah                  int main (void)
#define             kaj_shesh                   return 0
#define             sf(x)                       scanf ("%d", x)         
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

const int N = 1000;

void multiply(int *a, int &n, int no) {
    int carry = 0;
    for(int i = 0; i < n; i++) {
        int p = a[i] * no + carry;
        a[i] = p % 10;
        carry = p / 10;
    }

    while(carry) {
        a[n] = carry % 10;
        carry = carry / 10;
        n++;
    }
}

void big_fact(int number) {
    int a[N] = {0};
    a[0] = 1;
    int n = 1;

    for(int i = 2; i <= number; i++) {
        multiply(a, n, i);
    }

    // Print the factorial
    for(int i = n - 1; i >= 0; i--) {
        cout << a[i];
    }
    cout << endl;
}
Bishmillah 
{
    /*
		freopen ("input.txt","r",stdin);
		freopen ("output.txt","w",stdout);
    */
   int n ;
   cin >> n;
   big_fact(n);
   //for(int i = 0 ; i < n ; i++) cout << a[i] << " "
   


    kaj_shesh;
}