#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e8;
int solve(vector<string>& grid) {
	int n = grid.size();
	vector<vector<int>> dp(n, vector<int>(n, -INF));
	vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(n, {-1, -1}));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 'X') {
				continue;
			}

			if (i - 1 >= 0 and dp[i - 1][j] > dp[i][j]) {
				dp[i][j] = dp[i - 1][j];
				parent[i][j] = {i - 1, j};
			}
			if (j - 1 >= 0 and dp[i][j - 1] > dp[i][j]) {
				dp[i][j] = dp[i][j - 1];
				parent[i][j] = {i, j - 1};
			}

			dp[i][j] += (grid[i][j] == '$');
		}
	}

	int i = n - 1, j = n - 1;
	vector<pair<int, int>> path;
	while (i != -1 and j != -1) {
		if (grid[i][j] == 'X') {
			return 0;
		}

		path.push_back({i, j});
		auto par = parent[i][j];
		i = par.first, j = par.second;
	}

	for (auto cell : path) {
		grid[cell.first][cell.second] = '*';
	}

	return dp[n - 1][n - 1];
}

int getMaxMangoes(vector<string> gridA) {
	int n = gridA.size();
	if (gridA[n - 1][n - 1] == 'X') {
		return 0;
	}

	return 2 * solve(gridA) + 2 * solve(gridA);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<string> gridA(n);
    for (auto &row : gridA) {
    	cin >> row;
    }
    
    cout << getMaxMangoes(gridA) << "\n";

    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/  

	