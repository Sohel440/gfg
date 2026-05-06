// #include<bits/stdc++.h>
// using namespace std;

// unordered_map<int,bool>mp;

// bool dfs(int n, int m) {
//     mp[n] = true;
//     if(n == m) return true;
//     if(n % 3 != 0) return false;  // n = 3x means x + 2x
   
//     bool x = dfs(n / 3, m);
//     bool Two_x = dfs(2LL * (n / 3), m);
//     return x or Two_x;
// }

// void kaj() {
//     int n;
//     cin >> n;

//     vector<long long > a(n);
//     for(int i= 0 ; i < n ; i++){
//         cin >> a[i];

//     }
//     sort(begin(a), end(a));

//     int cnt =0;
//     for(int i = 0 ; i < n ; i++){
//         int s = i+1 ;
//         int e = n-1;

//         while (s < e)
//         {
//             long long s = a[i] + a[s] + a[e];
//             long long ans = s *(s -a[i] ) *(s- a[s]) *(s -a[e]);
//             double res = sqrt(ans);

//             if(res > 0)  {cnt++ ; e++;}
//             else s++;



//         }
        
//     }
//     cout << cnt << endl;


// }

// int main() {
//     int t;
//     cin >> t;
//     while(t--) 
//         kaj();
// }


#include<bits/stdc++.h>
using namespace std;

void kaj() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    map<int,int> mp;
    for(auto i : a){
        mp[i]++;

    }
    int  ans =0;

    for(auto  i : mp){
        
        int k = i.second;
        ans += k*(k-1)*(k-2)/6;
      ;

        int ind =lower_bound(a.begin(), a.end(), i.first)- a.begin();
        ans += k*(k-1)/2 * ind ;
       // ans *= ind;


    }
    cout << ans<< endl;

}

int main() {
    int t;
    cin >> t;
    while(t--) 
        kaj();
    return 0;
}
