#include<bits/stdc++.h>
using namespace std;


#define          ll                  long long int
#define          pb                  push_back 
#define          Bishmillah          int main()
#define          MOD                 1000000000
#define          fr0(i,n)            for(ll i = 0; i < n ; i++)
#define          fr1(i,n)            for(ll i = 1; i <= n ; i++)
#define          V                   vector
ll k;
vector<ll> a,b,c;

vector<vector<ll>> multiply(vector<vector<ll>> A , vector<vector<ll>> B){
   
      V<V<ll>> C(k+1 , V<ll>(k+ 1));

      fr1(i,k){
        fr1(j,k){
            fr1(x , k){
                C[i][j] = C[i][j] + ((A[i][x] * B[x][j])%MOD)%MOD;
            }
        }
      }
      return C;
}
vector<vector<ll>> power(vector<vector<ll>> A , ll p){

    if(p == 1){
        return A;
    }

    if(p & 1){
        return multiply(A , power(A ,p-1));

    }
    vector<vector<ll>> X = power(A ,p/2 );
    return multiply(X,X);
}

ll compute (ll n){
    if (n == 0){
        return 0;
    }

    if(n <= k){
        return b[n-1];
    }

    vector<ll>F(k+1);
    //step 1:
    fr1(i,k){
        F[i] = b[i-1];
    }
    
    vector<vector<ll> > T(k + 1 , vector<ll>(k+1));
    
    fr1(i , k){
        fr1(j , k ){
            
            if(i < k){

                if(j == i + 1){
                    T[i][j] = 1;
                }else{
                    T[i][j] = 0;
                }


            }else{

                T[i][j]= c[k-j];
 
            }
        }
    }

    //step 3

    T = power(T, n-1);

    //step4
    ll res =0;
    fr1(i , k){
        res = (res +(T[1][i] * F[i])%MOD)%MOD;
    }


    return res;
}

Bishmillah{

   ll t , n;
   cin >> t;
   while(t--){

    cin >> k;
    fr0(i,k){
        ll x;
        cin >> x;
        b.pb(x);

    }
    fr0(i,k){
        ll x;
        cin >> x;
        c.pb(x);

    }
    cin >> n;
    cout << compute(n);

    b.clear();
    c.clear();

   }

   return 0;
}