#include<bits/stdc++.h>
using namespace std;

int GCD(int a , int b){
    return b== 0? a : GCD(b , a%b);
}


int x , y;

void ExtendedEuclid(int a , int b){
  if(b== 0){
    x = 1;
    y = 0;
    return;
  }

ExtendedEuclid(b , a%b);

int cx = y;
int cy = x - (a/b) *y;

x = cx;
y = cy;

}

int32_t main(){

    cout << __gcd(10 , 12) << endl;
    cout << GCD(3 , 6) << endl;

    ExtendedEuclid(18, 30);
    cout << x << " "<< y << endl;
}