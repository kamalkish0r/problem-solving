#include <bits/stdc++.h>
using namespace std;

void find_divisors(int n, map<int, int>& cnt) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt[i]++;
            if (n / i != i) {
                cnt[n / i]++;
            }
        }
    }
}

vector<long> getNumVectors(vector<int> keys, vector<vector<int>> queries) {
    map<int, int> cnt;
    for (int key : keys) {
        find_divisors(key, cnt);
    }

    int r = 0;
    for (auto query : queries) {
        r = max(r, query[1]);
    }

    vector<long> prefix_sum(r + 1);
    for (int i = 1; i <= r; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + cnt[i] * cnt[i];
    }

    vector<long> ans;
    for (auto query : queries) {
        long k = prefix_sum[query[1]] - prefix_sum[query[0] - 1];
        ans.push_back(k);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> keys = {6, 9, 10};
    vector<vector<int>> queries = {{2, 3}, {9, 10}};
    vector<long> ans = getNumVectors(keys, queries);

    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
