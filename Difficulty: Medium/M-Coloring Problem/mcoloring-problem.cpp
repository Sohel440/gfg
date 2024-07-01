//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
   int N;

bool isok(bool graph[101][101], int color[], int n, int m, int k) {
    for (int i = 0; i < N; i++) {
        if (color[i] == k && graph[i][n] == 1 && i != n) {
            return false;
        }
    }
    return true;
}

bool solve(bool graph[101][101], int color[], int n, int m) {
    if (n == N) {
        return true;
    }

    for (int i = 1; i <= m; i++) {
        if (isok(graph, color, n, m, i)) {
            color[n] = i;
            if (solve(graph, color, n + 1, m)) {
                return true;
            }
            color[n] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    N = n;
    int color[101] = {0}; // Initialize the color array with zeros

    return solve(graph, color, 0, m);
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends