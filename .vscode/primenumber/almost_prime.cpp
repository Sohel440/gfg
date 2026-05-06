#include<bits/stdc++.h>
using namespace std;


bitset<1000005> bit;
int n = 1000000;
vector<int> prime;

void bit_prime(){
    bit.set();
 bit[0] = bit[1] = 0;

    for(long long int i = 2 ; i<= n ; i++ ){
       // bit[i] = 1;

        if(bit[i]){
            prime.push_back(i);
           for (long long int  j = i * i ; j <= n ; j = j + i ){
            bit[j] = 0;
           }
        }
    }

}

// check that the large no prime or not 

// 10^12


// ans 

bool is_prime( long long No){
    if(No <=n){
        return bit[No] == 1? true: false;

    }

    for(int i = 0  ; (long long)prime[i] * (long long)prime[i] <= No;i++){
        if(No % prime[i] == 0){
            return false;

        }


    }

    return true;


}

// prime factor by coding block 

int  prime_factor(int n){
    
    int factor[n+1] = {};

    for(int i = 2 ; i <=n ; i++){
        if(!factor[i]){
            for(int j = i ; j <=n ; j= j + i){
                factor[j]++;
            }
        }
    }

    int ans =0;

    for(int i = 0 ; i <= n ; i++){
        if(factor[i] == 2){
            ans++;

        }

    }

    return ans;

}

int main(){

    
//  bit_prime();
//  for(int i = 0 ; i < 4 ; i++){
//     cout << prime[i]<< endl;
//  }

// cout << is_prime(2147483648) << endl;
// int arr[10] ={};
// for(int i =0 ; i< 9 ; i++){
//     cout << arr[i]<< " ";
// }

int n ;
cin >> n;

cout << prime_factor(n);

}