#include<bits/stdc++.h>
using namespace std;

unordered_map<int,bool>mp;

bool dfs(int n, int m) {
    mp[n] = true;
    if(n == m) return true;
    if(n % 3 != 0) return false;  // n = 3x means x + 2x
   
    bool x = dfs(n / 3, m);
    bool Two_x = dfs(2LL * (n / 3), m);
    return x or Two_x;
}

void kaj() {
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<int,int> mp,mp1;


    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
       // st.insert(a[i]);
    }
    
    for(int i = 0; i < m; i++) {
        cin >> b[i];//st1.insert(b[i])
        mp1[b[i]]++;

    }
    int x =0, y = 0;

    for(int i =1 ; i <= k ; i++){
        if(mp[i] > 0 && mp1[i] > 0){
            x +=1;
            y+=1;

        }else if(mp[i] > 0){
            x++;

        }else if(mp1[i]>0){
            y++;
        }else{
            cout << "NO"<< endl;
            return;
        }
    }
    if(x >= k/2 && y>= k/2){
        cout << "YES"<< endl;
    }
    else cout << "NO"<< endl;

}

int main() {
    int t;
    cin >> t;
    while(t--) 
        kaj();
}
