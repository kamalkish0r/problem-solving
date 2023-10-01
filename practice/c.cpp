#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

bool can_make_k_decker(long long k) {
    long long req_buns = k + 1;
    long long req_cheese = k;
    long long req_patties = k;

    long long min_req_burgers = (req_buns + 1) / 2;
    // buy n single burgers and m double burgers in total cost <= c
    // how to decide n, m?
    // single burger - 2 buns, 1 patty, 1 cheese and costs a
    // double burger - 2 buns, 2 patties, 2 cheese and costs b

    long long cost;
    long long made = 0;
    long long d, s;
    if (a * 2 >= b) {
        d = c / b;
        s = (c % b) / a;
    }
    else { 
        d = (c % a) / b;
        s = c / a;
    }

    long long cheese = 2 * d + s;
    long long buns = 2 * (s + d);
    return buns >= req_buns and cheese >= req_cheese;
}

void solve() {
    cin >> a >> b >> c;

    long long low = 0, high = LLONG_M;
    while (low + 1 < high) {
        long long k = low + (high - low) / 2;
        if (can_make_k_decker(k)) {
            low = k;
        }
        else {
            high = k;
        }
    }

    cout << (can_make_k_decker(high) ? high : low) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("r.txt", "w", stderr);
// #endif
    
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
