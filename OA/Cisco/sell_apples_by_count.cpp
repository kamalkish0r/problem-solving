#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int k, n; cin >> k >> n;
    vector<int> apples(n);
    for (int &apple : apples) {
    	cin >> apple;
    }

    sort(apples.begin(), apples.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
    	int j = lower_bound(apples.begin() + i, apples.end(), apples[i] + k) - apples.begin();
    	while (j == apples.size() or apples[j] - apples[i] > k) {
    		j--;
    	}
    	res = max(res, j - i + 1);
    }
    cout << res << "\n";

    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/  

