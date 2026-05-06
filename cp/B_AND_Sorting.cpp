#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main()
{
    // let the game begin!
    int t;
    cin >> t;
    while(t--){

        int n ;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        int ans =(1<<30)-1;
       // cout << bitset<30>(ans).to_string() << endl;

        vector<int> tt = a;
        // int ans = 0;

        sort(a.begin(), a.end());

        for(int i = 0 ; i < tt.size(); i++){
            if(tt[i] != a[i]){
                // int val =
               ans  &= a[i];
               
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}