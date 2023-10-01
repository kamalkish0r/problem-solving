#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r, c, a, b;
    cin >> r >> c >> a >> b;

    cout << (r > c ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
#ifndef ONLINE_JUDGE
    freopen("dim_sum_delivery_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("r.txt", "w", stderr);
#endif
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
