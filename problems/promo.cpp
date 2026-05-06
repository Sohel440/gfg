#include<bits/stdc++.h>
using namespace std;


#define ll long long int
#define v  vector<ll> 
#define pii pair<ll ,ll >




void int_t(){
	 #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w", stdout);

    #endif
}
void solve(){

	ll n , q;
	cin >> n>> q;

    v a(n);
    for(ll  i = 0  ; i < n ; i++){
    	cin >> a[i];
    }

  vector<pair<ll ,ll>> p;
    for(int i =0 ; i < q; i++){
    	int x , y;   cin >> x >> y;
    	p.push_back({x , y});
    }

    sort(begin(a) , end(a));

    for(auto i : p){

    	int x = i.first;
    	int y = i.second;
        priority_queue<int , vector<int> , greater<int>() > pq;

    	for(int j = n-1 ; j>= n - x + 1 ;j--){

            pq.push(a[j]);

    	}
    	int ans =0;

    	while(y--){
    		if(!pq.empty()){
            ans += pq.top();
            pq.pop();
           }


    	}

    	cout << ans << endl;
    }
	

}

int main(){
    int_t();

    int t;;
    cin >> t;
    while(t--){
    	solve();
    }