#include <bits/stdc++.h>
using namespace std;

#define ll              long long int
#define pb              push_back
#define Bishmillah      int main()
#define MOD             1000000000
#define fr0(i, n)       for (ll i = 0; i < n; i++)
#define fr1(i, n)       for (ll i = 1; i <= n; i++)
#define V               vector
#define st              set
#define ins             insert
#define mii             map<int, int>
#define pqr             priority_queue<ll>
#define yes             cout << "YES"<< endl
#define No             cout << "NO"<< endl

void solve()
{
  ll n;
  cin >> n;

  V<V<ll>> sohel(n, V<ll>(n - 1, 0));

  V<ll> p(n, 0);
  V<ll> cnt(n + 1, 0);

  fr0(i, n)
  {
    p[i] = i + 1;
    fr0(j, n - 1)
    {
      cin >> sohel[i][j];
      if (j == 0)
        cnt[sohel[i][j]]++;
    }
  }

  fr1(i, n)
  {
    if (cnt[i] == n - 1)
    {
      p[0] = i;
    }
  }

  fr0(i, n)
  {
    if (sohel[i][0] != p[0])
    {

      fr0(j, n - 1)
      {
        p[j + 1] = sohel[i][j];
      }
    }
  }

  for (auto i : p)
    cout << i << " ";

  cout << endl;
}
void solve2()
{

  ll n;
  cin >> n;

  V<ll> a(n);
  set<ll> s;

  mii cnt;

  fr0(i, n)
  {
    ll x;
    cin >> x;

    cnt[x]++;

    s.ins(x);
    s.ins(x + 1);
  }
  ll prevcnt=0;
  ll res =0;

  for(auto i : s){
     int curr = cnt[i];
     res += max(1LL*0 , curr - prevcnt );
     prevcnt = curr;
     
  }
   
   cout << res << endl;
   

}


void solve3(){
   int n;
    cin>>n;

    V<ll>opr(n), x(n);
    fr0(i,n){
      cin>>opr[i];
      cin>>x[i];
    }

   
    ll mx = INT_MIN;
      ll mn = INT_MAX;


V<ll> t;
  fr0(i, n){
    if(opr[i] == 1) mx= max(mx  ,x[i] );
    else if(opr[i] == 2) mn = min(mn ,x[i] );
    else{ if(opr[i] == 3)t.pb(x[i]);}
  }
  
  set<ll>s;
  // cout << mx << " "<< mn<< endl;
  if(mx> mn){
    cout << 0 << endl;
    return;

  }

  while(t.size()!= 0){
    ll f = t.back();
    t.pop_back();
    if(f >= mx && f <= mn) s.ins(f);
  }


  cout << mn - mx+1 - s.size()<< endl;

}

void solve4(){
  int n;
    cin>>n;

    vector<int>a(n), b(n);
    for(int i = 0; i<n; i++){
      cin>>a[i];
      cin>>b[i];
    }

    vector<int>not_equal;
    int more = INT_MIN;
      int less = INT_MAX;

      bool found = false;

    for(int i = 0; i<n; i++){
      
      if(a[i] == 1) more = max(more, b[i]);
      if(a[i] == 2) less = min(less, b[i]);

      else{
        if(a[i] == 3) not_equal.push_back(b[i]);
      }
    }

    // cout<<more<<" "<<less;

    if(more > less){
       cout<<0<<endl;
       return;
    }

    set<int>s;

    int ans = 0;
    while(not_equal.size() != 0){
      int ele = not_equal.back();
      not_equal.pop_back();
      if(ele >= more and ele <= less) s.insert(ele);
    }

      cout<<less - more + 1 - s.size()<<endl;

}
void solve5(){
  int n;
  cin >> n;

  V<ll> s(n);
  fr0(i,n){
    cin >> s[i];
  }

  pqr pq;
  ll ans=0;

  for(auto i : s){
    if(i > 0){
      pq.push(i);
    }else{
     if(!pq.empty()){
     ans = pq.top() +ans;

      pq.pop();
     }
    }
  }

  cout << ans << endl;

}
void solve6(){
  ll n ,k;
  
  cin >> n >> k ;
  ll arr[n][n];
  fr0(i, n){
    fr0(j ,n){
      cin >> arr[i][j];
    }
  }
  ll req =0;
  fr0(i,n){
    fr0(j,n){
      if(arr[n-1-i][n-1-j] != arr[i][j]) req++;
    }
  }

  req /=2;
  if(k>=req &&(n%2 == 1 or (k-req) %2 == 0)) yes;
  else No;



} 
void solve7(){
  
  ll n;
  cin >> n;

  vector<ll> freq(26,0);
  string s;
  cin >> s;
  V<ll>su(n), p(n);
  set<char> cnt;

  for(int i = 0 ; i < n; i++){
    cnt.ins(s[i]);
    p[i] = cnt.size();

  }
  cnt.clear();
  for(ll i = n-1 ;i >=0 ; i--){
    cnt.insert(s[i]);
    su[i] = cnt.size();
  }

  ll ans = INT_MIN;
  fr0(i,n-1){
    ans = max(ans , p[i] + su[i+1]);
  }
  cout << ans << endl;

  // map<char,int> mp;
  // int i=0;
  // for( i = 0 ; i < n ; i++){
  //   if(mp.find(s[i]) != mp.end()){
  //     break;
  //   }
  //   mp[s[i]] = i;
  // }


  // string sa = s.substr(0 , i);
  // string sb = s.substr(i , s.size()-i);
  // // cout << sa << " "<< sb << endl;

  // set<char>s1,s2;
  // fr0(k , sa.size()){
  //      s1.ins(sa[k]);
  // }
  // fr0(k,sb.size()){
  //   s2.ins(sb[k]);
  // }

  // cout << s1.size()+s2.size()<< endl;


}
void fun(){
 string s;
    cin >> s;

    size_t t = s.find_last_not_of('0');
    string a = s.substr(0, t+1);
    cout << a << endl;
}

const ll N = 1000005;
ll p[N];

void f(){
  ll n;
  cin >> n;
  for(int i = 1 ; i<= n ; i++){
    p[i]=0;
  }
  vector<ll > ans;

  for(ll i = n; i >=1 ; i--){
      if(p[i] == 0){

        int temp = i;
        p[i] = 1;
        ans.push_back(i);
        while(temp %2 == 0){
          p[temp/2] = 1;
          ans.pb(temp/2);
          temp /=2;

        }
      }

        
      }

      for(auto i: ans) cout << i << " ";
      cout << endl;

  }

void A(){
  
  ll x[4],y[4];
  fr0(i,4){
    cin >> x[i]>> y[i];
  }

  sort(x , x+4);
  sort(y,y+4);

  int l= max((y[2]- y[1] ) , (x[2]- x[1]));
  int ans = l*l;
  cout << ans << endl;

}  
void B(){
  ll n;
  cin >> n;

  string a;
  cin >> a;
  string b;
  cin >> b;
  

  ll cnt =0,cnt1=0;
  fr0(i,n){
    if(a[i] == '0' && b[i] != '0') cnt++;

  }
  fr0(i,n){
    if(b[i]== '0' && a[i] == '1') cnt1++;

  }
 cout << max(cnt ,cnt1) << endl;

}
void C(){
  ll n, f, a, b;
  cin >> n >> f >> a >> b;
  vector <ll> vec(n);
  for (int i = 0; i < n; i++){
    cin >> vec[i];
  }
  ll pre = 0;
  ll mn;
  fr0 (i,n)
  {
    mn = min(b, abs(vec[i] - pre) * a);
    f -= mn;
    pre = vec[i];
  }
  if (f > 0) cout << "YES\n";
  else cout << "NO\n";
}
void make_it_zer0(){
  ll n;
  cin >> n;
  ll arr[n];
  fr0(i,n){
    cin >> arr[i];

  }
  
  if (n & 1) {
		cout << "4" << '\n';
		cout << "1 " << n - 1 << '\n';
		cout << "1 " << n - 1 << '\n';
		cout << n - 1 << ' ' << n << '\n';
		cout << n - 1 << ' ' << n << '\n';
	} else {
		cout << "2" << '\n';
		cout << "1 " << n << '\n';
		cout << "1 " << n << '\n';
	}

}
void line_trip(){
  ll n , k;
  cin >> n >> k;

  V<ll> a(n);
  ll prev = 0;
  ll mx = INT_MIN;

  fr0(i,n){
    cin >> a[i];
    ll diff  = a[i]-prev;
    mx = max(mx, diff);
    prev = a[i];
  }
  
  ll ans = max(mx , 2*(k-prev));

  cout << ans << endl;

}


void c(){

  ll n ,k;
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
Bishmillah
{

  int t;
  cin >> t;
  while (t--)
  {
//
make_it_zer0();

   
  }

 


  return 0;
}