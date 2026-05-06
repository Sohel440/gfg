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

int getPrime(int n){

    while( n % 2 == 0){
        return 2;
        n = n /2;
    }
    for(int i= 3 ; i <= sqrt(n); i++){
        while(n % i == 0){
            return i;
            n = n/i;
        }
    }
    if( n > 2) return n;

}
void kaj() {
   
   int l , r;
   cin >> l >> r;

   if(r <= 3) {cout << -1 << endl;}

  else{
    if(l < r) {
                if(r%2 != 0) {
                    r--;
                }
                cout<<2<<" "<<r-2<<endl;
            }
            else { // l == r
                int prime = getPrime(l);
                if(prime == l)
                    cout<<-1<<endl;
                else
                    cout<<prime<<" "<<l-prime<<endl;
            }

  }


}

int main() {
    int t;
    cin >> t;
    while(t--) 
        kaj();
}
