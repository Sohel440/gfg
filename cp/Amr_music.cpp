/*#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main()
{
  vector<pair<int,int>> d;
  int n ,k ,t;
  cin >> n >> k;

  for(int i = 1 ; i <= n ;i++){
    cin >> t;
    d.push_back({t , i});
  }
  sort(d.begin(), d.end());

  int cnt =0;
  while(1){
    k = k - d[cnt].first;
    if(k < 0) break;
    cnt++;


  }

  cout << cnt <<endl;
  for(int i = 0 ; i < cnt; i++){

    cout << d[i].second << " ";
  }

}*/
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     string s;
//     string t;
//     cin >> s;
//     cin >> t;

//     string a, b;

//     // Extract digits for the first time (s)
//     for (int i = 0; i < s.size(); i++) {
//         if (s[i] == ':') {
//             // Once ':' is found, we've extracted the hours, so now we collect the minutes.
//             for (int j = i + 1; j < s.size(); j++) {
//                 if (isdigit(s[j])) {
//                     a.push_back(s[j]);
//                 }
//             }
//             break;
//         }
//         if (isdigit(s[i])) {
//             a.push_back(s[i]);
//         }
//     }

//     // Extract digits for the second time (t)
//     for (int i = 0; i < t.size(); i++) {
//         if (t[i] == ':') {
//             // Once ':' is found, we've extracted the hours, so now we collect the minutes.
//             for (int j = i + 1; j < t.size(); j++) {
//                 if (isdigit(t[j])) {
//                     b.push_back(t[j]);
//                 }
//             }
//             break;
//         }
//         if (isdigit(t[i])) {
//             b.push_back(t[i]);
//         }
//     }

//     int clock1 = stoi(a);
//     int clock2 = stoi(b);


//     // Calculate the midpoint of the two times
//   cout << clock1 <<" " << clock2 << endl; 

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define FOR(i,N) for(int i = 0 ;i <N ;i++)

// int main(){

//     string s1, s2;
//     cin >> s1 >> s2;
//     int N = s1.size();
//     string t1 , t2;

//     FOR(i,N){
//         if(s1[i] == ':'){
//             for(int j = i +1 ; j < N ; j++){
//                 t2.push_back(s1[j]);
//             }
//         }
//         t1.push_back(s1[i]);
//     }
//     string t3 , t4;

//       FOR(i,N){
//         if(s2[i] == ':'){
//             for(int j = i +1 ; j < N ; j++){
//                 t4.push_back(s2[j]);
//             }
//         }
//         t3.push_back(s2[i]);
//     }

//     int h1 = stoi(t1);
//     // cout << h1;
//     int h2 = stoi(t3);
//     // cout << h2;

//     int m1 = stoi(t2);
//     int m2 = stoi(t3);


//     int diff = abs(h1 - h2);
//     cout << diff << " ";

//     int hour = diff * 60;
//     cout << hour << endl;

//     int average = hour /2;
//  cout << average << endl; 







// }

// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//     int h1 , m1 ;
//      cin >> h1 >> m1;
//     int h2 , m2;
   
//     cin >> h2 >> m2;

//     int t1 = h1 * 60 + m1;
//     int t2 = h2 * 60 + m2;

//     int avg = (t1 + t2)/2;

//     cout << avg/60 <<":"<< avg%60<< endl;
// }
/*#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int h1, m1;
	scanf("%d:%d", &h1, &m1);
	int h2, m2;
	scanf("%d:%d", &h2, &m2);
	int t1 = h1 * 60 + m1;
	int t2 = h2 * 60 + m2;
	int t3 = (t1 + t2) / 2;
	printf("%02d:%02d\n", t3 / 60, t3 % 60);
	
	return 0;
}*/

// #include<iostream>
// #include <vector>

// using namespace std;




// int main(){
//     int t ; 
//     cin >> t;
//     while(t--){
//         int n ; 
//         cin >> n ; 

//         vector<int>v(n) ; 
        
//         for(int i = 0 ; i<n ; i++){
//             cin >> v[i] ;
//         }

        
//         int ans = 1; 

//         for(int i = 0 ; i< n ;i ++){
//             if(v[i] == ans){
//                 ans+=2 ;
//                 //cout << "val : " << val << endl; 
//             }
//             else{
//                 ans++ ; 
//             }
//         }

//         cout << ans-1 << endl; 
        
//     }
// return 0 ;
// }
// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//   int n ;
//   cin >> n ;

//  int v[n];

//   for(int i = 0 ; i < n ; i++){
//    cin >>v[i];

//   }

//   vector<int> ans;
   
//   if(v[0] == 1) ans.push_back(2);
//   else
//   ans.push_back(1);

 
//  for(int i = 1 ; i < n ; i++){
//   int f = ans[i-1] +1;
//   if(f == v[i]){
//     ans.push_back(f+1);

//   }
//   else{
//     ans.push_back(f);
//   }
//  }

//  for(auto i : ans) cout << i << " ";

// cout << ans[n-1] << endl;
 



// }

//! Bismillahi-Rahamanirahim.
/** ========================================**
 ** @Author: sohel Mollick ( PGEC, CSE'34)
 ** @Category:CP
/** ========================================**/

// #include<bits/stdc++.h>
// #include<stdio.h>
// using namespace std;


// #define ll                  long long
// #define scl(n)              cin>>n;
// #define scc(c)	            cin>>c;
// #define fr(i,n)             for (ll i=0;i<n;i++)
// #define fr1(i,n)            for(ll i=1;i<=n;i++)
// #define pfl(x)              printf("%lld\n",x)
// #define pb                  push_back
// #define l(s)                s.size()
// #define asort(a)            sort(a,a+n)
// #define all(x) 	            (x).begin(), (x).end()
// #define dsort(a)            sort(a,a+n,greater<int>())
// #define vasort(v)           sort(v.begin(), v.end());
// #define vdsort(v)           sort(v.begin(), v.end(),greater<int>());
// #define uniquee(x)          x.erase(unique(x.begin(), x.end()),x.end())
// #define pn                  cout<<endl;
// #define md                  10000007
// #define inf                 1e18
// #define debug               cout<<"Monti valo nei "<<endl;
// #define ps                  cout<<" ";
// #define Pi                  acos(-1.0)
// #define mem(a,i)            memset(a, i, sizeof(a))
// #define tcas(i,t)           for(ll i=1;i<=t;i++)
// #define pcas(i)             cout<<"Case "<<i<<": "<<endl;
// #define fast 	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)



// int main()
// {
//     fast;
//     ll t;
//     cin>>t;
//     while(t--)
//     {
//         ll m,n,b,c,d,i,j,k,x,y,z,l,q,r;
//         string s1, s2, s3, s4;

//         ll cnt=0,sum=0;
//         bool ans=0;
//         cin>>s1>>s2;

//         //sort(all(s1));
//         vasort(s1);

//         for(i=0; i+l(s1)<= l(s2); i++)
//         {
//             s3=s2.substr( i, l(s1));
//             sort(all(s3));
//            // cout<<s1<<" "<<s3<<endl;
//             if(s1==s3){ans=1;break;}
//         }

//         if(!ans)  cout<<"NO"<<endl;
//         else cout<<"YES"<<endl;

//     }

//     return 0;
// }

// ///Before submit=>
// ///    *check for integer overflow,array bounds
// ///    *check 


#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll                  long long
#define scl(n)              cin>>n;
#define scc(c)	            cin>>c;
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
#define pfl(x)              printf("%lld\n",x)
#define pb                  push_back
#define l(s)                s.size()
#define asort(a)            sort(a,a+n)
#define all(x) 	            (x).begin(), (x).end()
#define dsort(a)            sort(a,a+n,greater<int>())
#define vasort(v)           sort(v.begin(), v.end());
#define vdsort(v)           sort(v.begin(), v.end(),greater<int>());
#define uniquee(x)          x.erase(unique(x.begin(), x.end()),x.end())
#define pn                  cout<<endl;
#define md                  10000007
#define inf                 1e18
#define debug               cout<<"Monti valo nei "<<endl;
#define ps                  cout<<" ";
#define Pi                  acos(-1.0)
#define mem(a,i)            memset(a, i, sizeof(a))
#define tcas(i,t)           for(ll i=1;i<=t;i++)
#define pcas(i)             cout<<"Case "<<i<<": "<<endl;
#define fast 	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>
using namespace std;
int main() {

    
    // int t;
    // scl(t);

    // while(t--){
    // string s1 , s2 , s3 , s4;
    // cin >> s1 ;
    // cin >> s2;
    // bool ans =0;
    // vasort(s1);
    // for(int i = 0 ; i+l(s1) <=l(s2) ;i++){
    //     s3 =s2.substr(i , l(s1));
    //     vasort(s3);
    //     if(s1 == s3){
    //         ans = 1;
    //         break;
    //     }
    // }
    // if(ans == 1) cout << "YES" << endl;

    // else
    // cout << "NO" << endl;


    // }
    // int n1 , n2;
    // cin >> n1 >> n2;
    // int var=0;
    // for(int i = n1 ; i <= n2 ; i++){
    //   int digit = i;
    //   set<int> st;
    //   int cnt =0;
    //   while(digit > 0){
    //     cnt++;
    //     int rem = digit%10;
    //     st.insert(rem);
    //     digit /= 10;
        
    //   }
    //   if(st.size() == cnt) var++;
    // }
    // cout << var << " ";

    // string s;
    // cin >> s;

    // vector<string > str = {"break" , "for" , "defer" , "Var" , "fun"};
    // map<string , int> mp;
    // for(auto i : str){
    //   mp[i]++;
    // }
    
    

    // if(mp.find(s) != mp.end()){
    //   cout << s <<" is keyword";

    // }
    // else{
    //   cout << s << " is not a Keyword" << endl;
    // }


    // return 0;


   int t;
   cin >> t;
   while(t--){
   int n , k ;
   cin >> n >> k;
   
   vector<int> a(n);
   for(int i = 0 ; i < n ; i++){
      int x;
      cin >> x;
      a.push_back(x);
   }
   
   for(auto i : a){
      if(i == k){
         cout << "YES" << endl;
         return 0;
    }
      
   }
   cout << "NO" << endl;
   }
   return 0;
    
}