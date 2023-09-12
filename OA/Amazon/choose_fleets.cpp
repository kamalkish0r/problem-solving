#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> dp;

int solve(int i, int sum, vector<int>& wheels) {
    if (i == wheels.size() or sum <= 0) {
        return sum == 0;
    }

    if (dp[i][sum] != -1) {
        return dp[i][sum];
    }

    return dp[i][sum] = solve(i, sum - wheels[i], wheels) + solve(i + 1, sum, wheels);
}

void pre() {
    int n = 1e6;
    dp.resize(2, vector<int>(n + 1, -1));
    vector<int> wheels = {2, 4};
    for (int i = n; i > 0; i--) {
        solve(0, i, wheels);
    }

    for (int i = 1; i <= 10; i++) {
        cout << i << " : ";
        cout << dp[0][i] << " " << dp[1][i] << "\n";
    }
}

vector<int> chooseFleets(vector<int> wheels) {
    vector<int> res;
    for (int wheel : wheels) {
        res.push_back(dp[0][wheel]);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    pre();

    vector<int> wheels = {4, 5, 6};
    vector<int> res = chooseFleets(wheels);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/  

