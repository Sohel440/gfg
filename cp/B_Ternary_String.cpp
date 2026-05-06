//Let's start with the name of Allah
//sohel440

/*author : sohel440*/

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
void yes(){cout << "YES"<< endl;};
void no(){cout << "NO"<< endl;}; 
template <typename V>
void pop_front(V & v)
{
    assert(!v.empty());
    v.erase(v.begin());
}

template <typename T>
void input(T& arr) {
    for (auto& element : arr) {
        cin >> element;
    }
}


template<typename T>
void printArray(T &arr){
    for(auto tt: arr){
        cout << tt<< " ";
    }
    cout << endl;
}



void kaj() {
   
   string s;
   cin >> s;


   unordered_map<char , int> mp;
   int i =0;
   int j =0;
   

   int ans = INT_MAX;

   while(j < s.size()){
      
      mp[s[j]]++;
      while(mp.size() == 3){
        ans = min(ans , j-i+1);
         
         mp[s[i]]--;
         if(mp[s[i]] == 0){
            mp.erase(s[i]);
         }
         i++;
         
      }

      j++;

   }  
   if(ans == INT_MAX){
      ans =0;
   }
   cout << ans << endl;    
    
}


int32_t main() {
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int t;
   cin >> t;
   while (t--)
        kaj();

    return 0;
}