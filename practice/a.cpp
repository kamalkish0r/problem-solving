#include <bits/stdc++.h>
using namespace std;
#define long long int
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    a[0] = 2;
    a[1] = 3;
    int curr = 4;
    for (int i = 2; i < n; i++) {
        int prev = a[i - 2] + a[i - 1];
        while ((curr * 3) % prev == 0) {
            curr++;
        }
        a[i] = curr++;
    }

    cout << curr << "\n";
    // for (int i : a) {
    //     cout << i << " ";
    // }
    // cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) 
        solve();

    return 0;
}
