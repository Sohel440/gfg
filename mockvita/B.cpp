#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define forn( i , x,n) for(int i = x ; i < n  ;i++)
#define all(x) (x.begin(), x.end())
#define el cout << endl
#define yes cout << "YES"<< endl
#define no cout << "NO" << endl
#define P pair<ll,ll> 


const ll mod = 1000000007;

vector<int> build_suffix_array(const string& s) {
    int n = s.size();
    vector<int> suffix_array(n), rank(n), tmp(n);
    for (int i = 0; i < n; ++i) {
        suffix_array[i] = i;
        rank[i] = s[i];
    }

    for (int len = 1; len < n; len *= 2) {
        auto compare = [&](int i, int j) {
            if (rank[i] != rank[j])
                return rank[i] < rank[j];
            int ri = (i + len < n) ? rank[i + len] : -1;
            int rj = (j + len < n) ? rank[j + len] : -1;
            return ri < rj;
        };

        sort(suffix_array.begin(), suffix_array.end(), compare);

        tmp[suffix_array[0]] = 0;
        for (int i = 1; i < n; ++i)
            tmp[suffix_array[i]] = tmp[suffix_array[i - 1]] + compare(suffix_array[i - 1], suffix_array[i]);

        rank = tmp;
    }

    return suffix_array;
}


int longest_match( string& X, const string& Y,  vector<int>& suffix_array, int i) {
    int n = Y.size();
    int left = 0, right = n - 1, max_len = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        int suffix_start = suffix_array[mid];
        int match_len = 0;

        // Check how long the match goes
        while (static_cast<size_t>(match_len) + static_cast<size_t>(i) < X.size() &&
               static_cast<size_t>(suffix_start) + static_cast<size_t>(match_len) < Y.size() &&
               X[match_len + i] == Y[suffix_start + match_len]) {
            match_len++;
        }

        max_len = max(max_len, match_len);

        if (X[match_len + i] > Y[suffix_start + match_len])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return max_len;
}


int minStringFactor( string& X,  string& Y, int S, int R) {
    int n = X.length();
    string revY = Y;
    reverse(revY.begin(), revY.end());

    vector<int> suffix_array_Y = build_suffix_array(Y);
    vector<int> suffix_array_revY = build_suffix_array(revY);

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        if (dp[i] == INT_MAX) continue; 

     
        int match_len_Y = longest_match(X, Y, suffix_array_Y, i);
        if (match_len_Y > 0)
            dp[i + match_len_Y] = min(dp[i + match_len_Y], dp[i] + S);

        
        int match_len_revY = longest_match(X, revY, suffix_array_revY, i);
        if (match_len_revY > 0)
            dp[i + match_len_revY] = min(dp[i + match_len_revY], dp[i] + R);
    }

    return dp[n] == INT_MAX ? -1 : dp[n];
}
void kaj()
{
    string x , y;
    cin >> x >> y ;

    int a , b;
    cin >> a >> b;

    cout << minStringFactor(x , y, a ,b)<< endl;;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    kaj();
}