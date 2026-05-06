#include <iostream>
#include <cmath>
using namespace std;

void kaj() {
    int t;
    cin >> t;
    
    while(t--) {
        long long hc, dc, hm, dm, k, w, a;
        cin >> hc >> dc;
        cin >> hm >> dm;
        cin >> k >> w >> a;

        bool ok = false;

        
        for (int i = 0; i <= k; i++) {
            long long upgraded_hc = hc + i * a;  // Add i coins to health
            long long upgraded_dc = dc + (k - i) * w;  // Add remaining coins to damage
            
           
            long long man_get_damage = (upgraded_hc + dm - 1) / dm;  // Number of hits Monocarp endures (ceil)
            long long mon_get_damage = (hm + upgraded_dc - 1) / upgraded_dc;  // Number of hits monster endures (ceil)
            
            if (man_get_damage >= mon_get_damage) {
               cout << "YES"<< endl;
               ok = true;
               break;

            }
        }

        
          if(!ok)  cout << "NO" << endl;
        
    }
}

int main() {
    kaj();
    return 0;
}
