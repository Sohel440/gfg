/*sohel Mollick 
  i want to red coder 
  
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long

int N = 1e6;
vector<bool> prime(N, 0);

signed main()
{
    int t;
    cin >> t;
    int i, j;
    for (i = 0; i < N; i++)
    {
        prime[i] = 0;
    }
    for (i = 2; i * i < N; i++)
    {
        if (prime[i] == 0)
        {
            for (j = i * i; j < N; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    prime[0] = 1;
    prime[1] = 1;
    int ans = 0;
    int cnt=0;
    vector<int> sive;

    for (i = 0; i < N; i++)
    {
        if (prime[i] == 0)
        {
            sive.push_back(i);
        }
    }
    while (t--)
    {
        int n;
        cin>>n;
        if(n%2==0)
        {
            for(int i=0;i<n/2;i++)
            {
                cout<<sive[i]<<" "<<sive[i]<<" ";
            }
        }
        else
        {
            cout<<1<<" ";
            for(int i=0;i<(n-1)/2;i++)
            {
                cout<<sive[i]<<" "<<sive[i]<<" ";
            }
        }
        cout<<endl;
    }
}