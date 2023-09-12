#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e9;


int solve(int i, int target, vector<int>& a, vector<vector<int>>& dp) {
	if (i == a.size() or target <= 0) {
		return target == 0 ? 0 : -INF;
	}

	if (dp[i][target] != -1) {
		return dp[i][target];
	}

	int op1 = -INF, op2 = -INF;
	if (a[i] <= target) {
		op1 = 1 + solve(i + 1, target - a[i], a, dp);
	}
	op2 = solve(i + 1, target, a, dp);

	return dp[i][target] = max(op1, op2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, target;
    cin >> n >> target;
    vector<int> a(n - 1);
    for (int &i : a) {
    	cin >> i;
    }
    vector<vector<int>> dp(n - 1, vector<int>(target + 1, -1)); // change based on constraints
    cout << max(0LL, solve(0, target, a, dp)) << "\n";

    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/  

	