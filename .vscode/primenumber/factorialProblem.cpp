#include<bits/stdc++.h>
using namespace std;



int main(){



    int n , k;
    cin >> n >> k;
    int occ =0;
    int ans = INT_MAX;


    for(int i = 2 ; i*i <=k ; i++)
    {
        if(k %i == 0){

            occ = 0;
            while(k % i == 0){
                occ++;
                k = k /i;

            }

            // find the power of k power in factorial 


            int cnt =0;

            int p= i;
            while(p<= n){
                cnt += (n/p);
                p = p * i;
            }

            ans = min(ans , cnt/occ);
            

        }


    }

    if(k > 1){
      int cnt =0;
      int p = k;
      while (p <= n)
      {
        cnt += n/p;
        p  = p *k;
      }
      ans = min(ans , cnt);
    }
    cout << ans << endl;
    
    return 0;

}