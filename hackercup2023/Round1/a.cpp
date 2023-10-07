#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	cout.precision(18);
	int n; cin >> n;
    vector<double> x(n);
    for (auto &i : x) {
    	cin >> i;
    }

    sort(x.begin(), x.end());

    double dist = (x[n - 1] + x[n - 2]) / 2 - (x[1] + x[0]) / 2;
    if (n == 5) {
    	double dist1 = (x[n - 1] + x[n - 3]) / 2 - (x[1] + x[0]) / 2;
    	double dist2 = (x[n - 1] + x[n - 2]) / 2 - (x[2] + x[0]) / 2;
    	dist = max(dist1, dist2);
    }
    cout << dist << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("r.txt", "w", stderr);
#endif

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
    	cout << "Case #" << i << ": ";
    	solve();
    }


    return 0;
}