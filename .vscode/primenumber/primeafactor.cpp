#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define p pair<int, int>
#define pb  push_back

 int cnt =0;
vector<p> s;

void primeFactor(int n)
{
    for(int i = 2 ; i*i <= n ;i++){
       
        if(n%i == 0){
            cnt =0;
            while(n % 2 == 0){
                cnt++;
                n = n/i;

            }
            s.pb({i , cnt});
        }
    }

    if(n != 1) {
        s.pb({n , 1});
    }

    for(auto u : s){
        cout << u.first << "^" << u.second<< endl;

    }
}

int main()
{

    int n;
    cin >> n;

    primeFactor(n);

    return 0;
}