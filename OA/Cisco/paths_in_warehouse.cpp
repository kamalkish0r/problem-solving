#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;



// naive approch
int appraoch1(vector<vector<int>>& warehouse) {
	int n = warehouse.size(), m = warehouse[0].size();
	vector<vector<int>> dp(n, vector<int>(m, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!warehouse[i][j])
				continue;

			if (i - 1 >= 0) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
			}
			if (j - 1 >= 0) {
				dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
			}
		}
	}

	return dp[n - 1][m - 1];
}

// space optimised approach
int appraoch2(vector<vector<int>>& warehouse) {
	int n = warehouse.size(), m = warehouse[0].size();

	vector<int> dp(m, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!warehouse[i][j]) {
				dp[j] = 0;
				continue;
			}
			if (i == 0 and j == 0)
				continue;

			int up = 0, left = 0;
			if (j > 0 and warehouse[i][j - 1])
				left = dp[j - 1];
			if (i > 0 and warehouse[i - 1][j])
				up = dp[j];

			dp[j] = (up + left) % mod;
		}
	}

	return dp[m - 1];
}

int numPaths(vector<vector<int>>& warehouse) {
	return appraoch2(warehouse);
	// return appraoch1(warehouse);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int>> warehouse = {
    	{1, 1},
    	{0, 1}
    };

    // vector<vector<int>> warehouse = {
    // 	{1, 1, 1, 1},
    // 	{1, 1, 1, 1},
    // 	{1, 1, 1, 1}
    // };
    cout << numPaths(warehouse) << "\n";

    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/  

