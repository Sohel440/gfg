 /*author : sohel mollick 
  dept : C.S.E
  university: RKMGEC*/


#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <iostream>
#include <bits/stdc++.h>
// #include "utilities.cpp"
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define forn(i, x, n) for (int i = x; i < n; i++)
#define for1(i, x, n) for (int i = x; i <= n; i++)
#define vi vector<int>
#define vpp vector<pair<int,int>>
#define vs vector<string>
#define vll vector<long long>
#define in(x) scanf("%d", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define nl printf("\n")

int SetBit (int n, int X) { return n | (1 << X); }
int ClearBit (int n, int X) { return n & ~(1 << X); }
int ToggleBit (int n, int X) { return n ^ (1 << X); }
bool CheckBit (int n, int X) { return (bool)(n & (1 << X)); }
int row[] = {1,0,-1,0};
int col[] = {0,1,0,-1};
const int mod = 1e9 + 7;

int  moduo_korlam(int a , int b){
    
   int res = 1;

    while( b > 0 ){

        if(b & 1){
            res = res * a;

        }
        a = a*a;

        b = b>> 1;

    }
    return res;

}
bool solve(int mid , vector<int> &a , int c){
int total =0;
    forn(i,0,a.size()){
        

        int side = (2LL* mid) + a[i];
        int area = side * side;

        total +=area;
        if(total > c){
           return false;
        }
    }

    return true;
}
int six = 6;
int four = 4;

void kaj() {
       int  n , m;

       cin >> n >> m;
	    vector<pair<int,int>>diff;
	    for(int i=0;i<n;i++)
	    {
	        vector<pair<int,int>>vp;
	        for(int j=0;j<m;j++)
	        {  
                int k;
	            cin >> k;
	            vp.push_back(make_pair(k,0));
	        }
	        for(int j=0;j<m;j++)
	        {
	            int k ;
                cin >> k;
	            vp[j].second=k;
	        }
	        sort(vp.begin(),vp.end());
	        int ans=0;
	        for(int j=0;j<m-1;j++)
	        {
	            if(vp[j].second>vp[j+1].second)
	                ans++;
	        }
	        diff.push_back(make_pair(ans,i+1));
	    }


        
	    sort(diff.begin(),diff.end());
	    for(auto x:diff)
	        cout << (x.second)<<"\n";


}

int32_t main() {
   // int t;
   // cin >> t;
   // while(t--) 
        kaj();


    return 0;
}