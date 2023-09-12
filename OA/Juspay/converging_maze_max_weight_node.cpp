#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<int> weight(n, 0);
	for (int i = 0; i < n; i++) {
		int edge;
		cin >> edge;

		if (edge != -1) {
			weight[edge] += i;
		}
	}

	int max_weight = 0, max_weight_node = 0;
	for (int i = 0; i < n; i++) {
		if (weight[i] > max_weight) {
			max_weight = weight[i];
			max_weight_node = i;
		}
	}

	cout << max_weight_node << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) 
        solve();
        
    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/
		