//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool ok(int i, int j, vector<vector<int>>& grid) {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] != 0;
}

bool solve(int i, int j, int r, int c, vector<vector<int>>& grid) {
    if (i == r && j == c) {
        return true;
    }

    // Mark the cell as visited
    int temp = grid[i][j];
    grid[i][j] = 0;

    bool l = false, ri = false, u = false, d = false;

    if (ok(i, j + 1, grid)) {
        l = solve(i, j + 1, r, c, grid);
    }
    if (ok(i, j - 1, grid)) {
        ri = solve(i, j - 1, r, c, grid);
    }
    if (ok(i + 1, j, grid)) {
        d = solve(i + 1, j, r, c, grid);
    }
    if (ok(i - 1, j, grid)) {
        u = solve(i - 1, j, r, c, grid);
    }

    // Restore the cell's original value if needed
    grid[i][j] = temp;

    return l || ri || u || d;
}

bool is_Possible(vector<vector<int>>& grid) {
    int si, sj;
    int di, dj;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                si = i;
                sj = j;
            } else if (grid[i][j] == 2) {
                di = i;
                dj = j;
            }
        }
    }

    return solve(si, sj, di, dj, grid);
}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends