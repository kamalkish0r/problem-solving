#include <bits/stdc++.h>
using namespace std;

int get_index(int x, vector<int>& l, vector<int>& r) {
    int low = 0, high = l.size() - 1;
    while (low + 1 < high) {
        int mid = (low + high) >> 1;
        if (x >= l[mid] and x <= r[mid]) {
            return mid;
        }

        if (x > r[mid]) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    return (x >= l[low] and x <= r[low] ? low : high);
}

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> l(k), r(k);
    for (auto &i : l) {
        cin >> i;
    }
    for (auto &i : r) {
        cin >> i;
    }

    // string ss = s;
    int q; cin >> q;
    set<int> bp;
    vector<pair<int, int>> ranges, m_ranges;
    while (q--) {
        int x; cin >> x;
        int index = get_index(x, l, r);

        int a = min(x, l[index] + r[index] - x);
        int b = max(x, l[index] + r[index] - x);

        // cout << x << " : " << a << " " << b << "\n";
        ranges.push_back({a, b});

        // reverse(ss.begin() + a - 1, ss.begin() + b);
    }

    sort(ranges.begin(), ranges.end());


    int sum = 0;
    vector<int> prefix_sum(n + 10, 0);
    for (int i = 0; i < ranges.size(); ) {
        int max_till_now = ranges[i].second;
        int i_max = i;

        for (int j = i + 1; j < ranges.size(); j++) {
            if (max_till_now < ranges[j].first) {
                break;
            }
            max_till_now = max(max_till_now, ranges[j].second);
            i_max = j;
        }

        for (int j = i; j <= i_max; j++) {
            prefix_sum[ranges[j].first]++;
            prefix_sum[ranges[j].second + 1]--;
        }

        // cout << i << " :: " << i_max << " " << " " << ranges[i].first << " " << max_till_now << "\n";
        int left = ranges[i].first, right = max_till_now;
        int mid = (left + right) / 2;
        for (int j = left; j <= right; j++) {
            sum += prefix_sum[j];

            if (sum % 2 and j <= mid) {
                // cout << "swapping " << s[j - 1] << s[right - 1 - (j - left)] << " " << j - 1 << " " << right - 1 - (j - left) << "\n";
                swap(s[j - 1], s[right - 1 - (j - left)]);
            }
        }
        // cout << "\n";

        i = i_max + 1;
    }

    cout << s << "\n";
    // cout << ss << "\n\n";
    // assert(ss == s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) 
        solve();

    return 0;
}
