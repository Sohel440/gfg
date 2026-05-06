#include <bits/stdc++.h>
using namespace std; 

const int  N = 100005 ;
#define lli     long long int

lli modular_multi(lli a , lli b , lli n){

    lli res =0;
    while(b){

        if(b & 1ll){
            res = (res +a);

        }
        res = res %n;
        b /= 2;
        a *= 2;
        a %= n;

       

    }

    return res;

}
lli inv (lli base , lli p , lli m){
    lli res = 1;
    while(p){
        if(p&1ll){
          
          res = modular_multi(res , base , m);
          
        }
        base = modular_multi(base , base , m);
        base = base % m;
        p /= 2;


    }
    return res;

}





bool miller(lli n){

    if(n ==1) return false;
    if(n==2 ) return true;
    if(n %2 == 0) return false;
// n id odd 
    lli d = n-1;
    lli s = 0;

    while(d%2 ==0){
        s++;
        d /= 2;
    }

    // n -1 = d * pow (2 , s);

    //now d is odd;

    vector<lli> a ({2 ,3 ,5 , 7 , 11 ,13 , 17 , 19 ,23 });
// a represent ramdom number 
    for(lli i = 0 ; i < a.size();i++){
        
        if(a[i]> n-2) continue;
        lli ad = inv(a[i] , d , n);
        cout << "ad "<< ad << endl;
        if(ad %n == 1) continue;;
        bool prime = false;

        for(lli r = 0 ; r <= s-1 ; r++ ){
            lli rr = inv(2 , r , n);
            lli ard = inv (ad , rr , n);
            cout << ard << endl;
            if(ard %n ==n-1 ){
                prime = true;
                break;
            }


        }
        if(prime == false) return false;
    }

    return true;
    


}
int  main(){

    //  primeF(2023);
    //  for(auto i : f) cout << i << " ";
  

    //  lli b , m;
    //  cin >> b >> m;
    //  cout << inv(b  , m-2 , m) << endl;
    //  cout << mi(b , m);

    // cout << modular_multi(12, 3, 10000);


    lli t;
    cin >> t;
    while(t--){
        lli n ;
        cin >> n;

        if(miller(n))cout << "prime"<< endl;
        else cout << "Not prime"<< endl;

    }
    
}