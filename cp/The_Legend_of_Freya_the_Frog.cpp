#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
       int x, y , k;
       cin >> x >>y >> k;
       int a =0, b=0;
       if(x % k==0){
        a = (x/k);
        
       }else{
        a = (x/k)+1;
       }

       if(y % k==0){
        b = (y/k);
        
       }else{
        b = (y/k)+1;
       }


       int mn = min(a , b);
       int mx = max(a , b);
       int ans = 2*mx;
       if(a  > b)ans-=1;

       cout << ans <<endl;



    }
    
    return 0;
}
