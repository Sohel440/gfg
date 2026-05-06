
/***

            Bismillahir Rahmanir Rahim
            Read in the name of Allah, who created you!!!
            Author : Sohel mointck
            Department of CSE, RKMGEC (WBUT), INDIA.

***/

#include <bits/stdc++.h>
using namespace std;

#define             jeno_joyer_khida_thake      int main ()
#define             kaj_shesh                   return 0
#define             sf                          scanf          
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

// void solve(){

    lld n;
    cin >> n;
    vlld a(n), b(n);
    lld i =0;
    for0(i , n){
        cin >> a[i];
    }
    i =0;
    for0(i ,n){
        cin >> b[i];
    }


    map<lld,lld> mp , mp1;
    lld  cnt =0;
    lld mx = LONG_LONG_MIN;
    
    for(int i= 0 ; i < n ; i++){
       cnt++;
       if(i == n-1 or a[i+1] != a[i] ){
          if(mp.find(a[i]) == mp.end()){
            mp[a[i]] = cnt;
          }else{
            mp[a[i]] = max( mp[a[i]] , cnt);
          }
          cnt =0;

       }
    }
    cnt =0;

      for(int i= 0 ; i < n ; i++){
       cnt++;
       if(i == n-1 or b[i+1] != b[i] ){
          if(mp1.find(b[i]) == mp1.end()){
            mp1[b[i]] = cnt;
          }else{
            mp1[b[i]] = max( mp1[b[i]] , cnt);
          }
          cnt =0;

       }
    }
    
    lld m = LONG_LONG_MIN, m1 = LONG_LONG_MIN;

    for(auto i : mp){
       m = max(m , (mp[i.first] + mp1[i.first]));
    }
     for(auto i : mp1){
       m = max(m , (mp[i.first] + mp1[i.first]));
    }

    cout << m<< endl;

}


void fun(){

  lld n ,k;
  cin >> n >> k;
  string s;
  cin>> s;
    map<char , int> m;
  int cnt =0;
      for(int i= 0 ; i < n ; i++){
       cnt++;
       if(i == n-1 or s[i+1] != s[i] ){
          if(m.find(s[i]) == m.end()){
            m[s[i]] = cnt;
          }else{
            m[s[i]] = max( m[s[i]] , cnt);
          }
          cnt =0;

       }

    }
  
        int mx =INT_MIN;
    for(auto i : m){
      mx = max(mx, i.second);
    }
    

    cout << mx << " ";
    
  while(k--){
    char ch;

    cin >> ch;
    s.append(to_string(ch));

    int cnt =0;
      for(int i= 0 ; i < n ; i++){
       cnt++;
       if(i == n-1 or s[i+1] != s[i] ){
          if(m.find(s[i]) == m.end()){
            m[s[i]] = cnt;
          }else{
            m[s[i]] = max( m[s[i]] , cnt);
          }
          cnt =0;

       }

    }


    int mx =INT_MIN;
    for(auto i : m){
      mx = max(mx, i.second);
    }
    

    cout << mx << " ";
    

    

    


  }
  
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
        fun();
     }


    kaj_shesh;
}