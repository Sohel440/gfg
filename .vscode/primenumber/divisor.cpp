#include<iostream>
#include<vector>
#include<bitset>
using namespace std;


bitset<10000> bit;

int no_of_div(int n ){

    bit.set();
    for(long long int i =1 ; i <= n ; i++){
          
          if(n %i == 0){
            bit[i] =0;
          }

    }

    int cnt =0;

    for(int i = 1 ; i <= n ; i++){
        if(bit[i] == 0){
            cnt++;
        }
    }
    return cnt;

}

int main(){
   

     
     int t;
     cin >> t;
     while(t--){
        int n ;
        cin >> n ;

        int a = no_of_div(n);

        cout << a << endl;

     }


    return 0;
}