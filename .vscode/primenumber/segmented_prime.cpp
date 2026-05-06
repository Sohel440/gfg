#include<bits/stdc++.h>
using namespace std;


// bitset<1000005> bit;
int n = 1000000;
vector<int> prime;
  int p[100000] ={};
void segment(){
    for(int i = 2 ; i <= 100000 ; i++){
        if(p[i] == 0){
            prime.push_back(i);
            for(int j  = i ; j <= 100000 ;j += i){
                p[j]= 1;

            }
        }
    }

}

int main(){


segment();

int t;
cin >>t;

while(t--){

    int n , m;
    cin >> n >> m;

    bool seg[n-m+1];
    for(int i = 0 ; i < n-m + 1; i++){
        seg[i]=0;
    }

    for(auto x : prime){
        if(x * x > n){
            break;
        }
        int start = (m/x) * x;

        
        if(x>= m && x <= n) {
            start = x *2;
        }

        for(int i = start ; i <=n ; i+=x){

            seg[i-m] = 1;
        }
    }

    for(int i = m ; i <=n ; i++){
        if(seg[i-m] == 0 and i != 1){
            cout << i << endl;
        }
    }
}



}