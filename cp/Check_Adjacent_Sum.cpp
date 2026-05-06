//C. Assembly via Minimums
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
#define vi vector<int>
#define vpp vector<pair<int,int>>
#define vs vector<string>
#define vll vector<long long>
int row[] = {1,0,-1,0};
int col[] = {0,1,0,-1};
const int mod = 1e9 + 7;
std::unordered_set<char> u = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

   std::unordered_set<char> l = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

   char B = 'B';
   char b = 'b';

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        int aaa[n];
        int sum=0;

        for(int i=0;i<n;i++)
        {
            cin>>aaa[i];
            sum+=(2*aaa[i]);
        }
        while(q--)
        {
            int s;
            cin>>s;
            int sub=sum-s;
            bool f=false;
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(aaa[i]+aaa[j]==sub)
                    {
                        cout<<aaa[i]<<" ";
                        for(int k=0;k<n;k++)
                        {
                            if(k!=i && k!=j)
                            {
                                cout<<aaa[k]<<" ";
                            }
                        }
                        cout<<aaa[j]<<" "<<endl;
                        f=true;
                        break;
                    }
                }
                if(f)
                {
                    break;
                }
            }
            if(!f)
            {
                cout<<-1<<endl;
            }
        }
    }
}
