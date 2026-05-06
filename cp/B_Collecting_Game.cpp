#include <bits/stdc++.h>
using namespace std;
#define lld long long 
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<pair<lld, lld>> p;
    for(lld i = 0 ; i < n ; i++){
        lld x ;
        cin >> x;

        p.push_back({x,i});
    }

    sort(begin(p), end(p));
    vector<lld>pre(n , 0);
    pre[0] = p[0].first;

    for(int i = 1 ; i <  n ; i++){
        pre[i] = pre[i-1] + p[i].first;

    }

    stack<lld> ind;
    vector<lld> ans(n , -1);

    for(int i = 0 ; i < n ; i++){

        ind.push(p[i].second);
        if(i == n-1 or p[i+1].first > pre[i]){
            while(!ind.empty()){
                ans[ind.top()] = i;
                ind.pop();
            }
        }
    }

    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
