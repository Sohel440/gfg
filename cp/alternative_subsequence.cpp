
#include <bits/stdc++.h>

using namespace std;

bool fun (int n ){
     return n >0;
}
int main()
{
    int t;
    cin >> t;
    while(t--){
         
        	int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			int cur = a[i];
			int j = i;
          // cout <<"ami opor r i bhai: " << i << " ";
			while (j < n && fun(a[i]) == fun(a[j])) {
				cur = max(cur, a[j]);
				++j;
			}
            
			sum += cur;
           // cout << sum << " ";
			i = j - 1;
            //cout <<"i" << i << " ";
		}
		cout << sum << endl;
    }

    return 0;
}