#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int 
#define ip(x) 
    ll x;     
    cin >> x 
#define co(x) cout << x << endl 
#define inp(x, y) 
    ll x, y;      
    cin >> x >> y 
#define iput(a, b, c) 
    ll a, b, c;       
    cin >> a >> b >> c 
#define need_for_speed                
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
#define ff(i, a, b) for (int i = a; i < b; i++) 
int main() 
{ 
    need_for_speed 
        ip(t); 
    while (t--) 
    { 
        iput(n, a, b); 
        if (a == b) 
        { 
            if (n % (a + 1) != 0) 
                co("ALICE"); 
            else 
                co("BOB"); 
        } 
        else if (b > a && n > a) 
        { 
            co("BOB"); 
        } 
        else 
            co("ALICE"); 
    } 
    return 0; 
} 