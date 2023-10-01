#include <bits/stdc++.h>
using namespace std;

int n;
long long res;
void check(long long k, long long sum, vector<long long> a) {
    long long req = n * k - sum;
    if (req <= 0)
        return;
    a.push_back(req);
    sort(a.begin(), a.end());
    for (int i = 0, j = a.size() - 1; i < j; i++, j--) {
        if (a[i] + a[j] != k) {
            return;
        }
    }
    res = min(res, req);
}

void solve() {
    cin >> n;
    long long sum = 0;
    vector<long long> a(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (n == 1) {
        cout << "1\n";
        return;
    }

    res = LLONG_MAX;
    sort(a.begin(), a.end());
    // first element is not present then weight : new first element + second last element
    check(a[0] + a[a.size() - 2], sum, a);

    // last element is not present then weight : second element + new last element
    check(a[1] + a.back(), sum, a);

    // any middle element is not present then weight : first element + last element
    check(a.front() + a.back(), sum, a);

    cout << (res == LLONG_MAX ? -1LL : res) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
#ifndef ONLINE_JUDGE
    freopen("two_apples_a_day_input.txt", "r", stdin);
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
