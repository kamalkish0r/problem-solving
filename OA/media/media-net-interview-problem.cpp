#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
Given an array of size n and interval size k
find sum of c[i] for 1 <= i <= n, where 
c[i] = max{abs(max(interval) - a[i]) - abs(min(interval) - a[i])} for each interval i is part of.
max(interval) = max element in interval
min(interval) = min element in interval

1 <= n <= 1e6
1 <= k <= n
1 <= a[i] <= 1e9

testcase:
n = 6, k = 2
a = {1, 2, 3, 4, 5, 6}

possible intervals for 
i = 1:
[[1, 2]]
c[i] = 1 - 0 = 1

i = 2:
[[1, 2], [2, 3]]
c[i] = abs(3 - 2) - abs(1 - 2) = 0
.
.
.
*/


void print(vector<int>& a) {
    for (int i : a) {
        cout << i << " ";
    }
    cout << '\n';
}

vector<int> min_ending_at_i(int k, vector<int>& a) {
    vector<int> mn(a.size());
    deque<int> d;
    for (int i = 0; i < a.size(); i++) {
        if (d.size() >= k or (!d.empty() and d.front() == i - k)) {
            d.pop_front();
        }

        while (!d.empty() and a[d.back()] > a[i]) {
            d.pop_back();   
        }

        d.push_back(i);

        if (i >= k - 1) {
            mn[i] = a[d.front()];
            if (i == k - 1) {
                for (int j = 0; j < k; j++) {
                    mn[j] = a[d.front()];
                }
            }
        }
    }
    return mn;
}

vector<int> max_ending_at_i(int k, vector<int>& a) {
    deque<int> d;
    vector<int> mx(a.size());

    for (int i = 0; i < a.size(); i++) {
        while (d.size() >= k or (!d.empty() and d.front() == i - k)) {
            d.pop_front();
        }

        while (!d.empty() and a[d.back()] < a[i]) {
            d.pop_back();
        }

        d.push_back(i);

        if (i >= k - 1) {
            mx[i] = a[d.front()];
            if (i == k - 1) {
                for (int j = 0; j < k; j++) {
                    mx[j] = a[d.front()];
                }
            }
        }
    }
    return mx;
}

int max_interval(int i, vector<int>& mxs, vector<int>& mxe) {
    return max(mxe[i], mxs[i]);
}

int min_interval(int i, vector<int>& mns, vector<int>& mne) {
    return min(mns[i], mne[i]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto & i : a) {
    	cin >> i;
    }

    // c[i] = max{abs(max(interval)) - a[i]) - abs(min(interval) - a[i])}
    // c[i] = max(interval) + min(interval) - 2 * a[i]

    vector<int> mxe = max_ending_at_i(k, a); // max of interval ending at index i
    vector<int> mne = min_ending_at_i(k, a); // min of interval ending at index i
    reverse(a.begin(), a.end());
    vector<int> mxs  = max_ending_at_i(k, a); // max of interval starting at index i
    vector<int> mns = min_ending_at_i(k, a); // min of interval starting at index i
    reverse(mxs.begin(), mxs.end());
    reverse(mns.begin(), mns.end());

    vector<int> max_min_sum(n); // max_min_sum[i] : max of max + min over all intervals to which i belongs
    deque<int> d;
    for (int i = 0; i < n; i++) {
        if (d.size() >= k or (!d.empty() and d.front() <= i - k)) {
            d.pop_front();
        }

        while (!d.empty() and max_interval(d.back(), mxs, mxe) + min_interval(d.back(), mns, mne) < max_interval(i, mxs, mxe) + min_interval(i, mns, mne)) {
            d.pop_back();
        }

        d.push_back(i);

        max_min_sum[i] = max_interval(d.front(), mxs, mxe) + min_interval(d.front(), mns, mne);
    }

    vector<int> c;
    for (int i = 0; i < n; i++) {
    	c.push_back(max_min_sum[i] - 2 * a[i]);
    }

    cout << "mxe : ";
    print(mxe);
    cout << "mxs : ";
    print(mxs);
    cout << "mns : ";
    print(mns);
    cout << "mne : ";
    print(mne);

    cout << "max_min_sum : ";
    print(max_min_sum);

    for (auto i : c) {
    	cout << i << " ";
    }
    cout << "\n";

    return 0;
}
