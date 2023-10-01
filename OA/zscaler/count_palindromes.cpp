#include <bits/stdc++.h>
using namespace std;

int countPalindromes(vector<string> arr) {
    vector<int> sizes;
    map<char, int> cnt;
    for (auto &s : arr) {
        sizes.push_back(s.size());
        for (auto ch : s) {
            cnt[ch]++;
        }
    }

    int ans = 0;
    for (int s : sizes) {
        if (cnt.empty()) {
            break;
        }

        int req = s;
        if (req % 2) {
            char req_ch = '0';
            for (auto [key, f] : cnt) {
                if (f % 2) {
                    req_ch = key;
                    break;
                }
            }

            if (req_ch == '0') {
                req_ch = cnt.begin()->first;
            }

            cnt[req_ch]--;
            req--;
            if (cnt[req_ch] == 0) {
                cnt.erase(req_ch);
            }
        }


        while (req > 0 and !cnt.empty()) {
            char curr = '0';
            for (auto [key, f] : cnt) {
                if (f > 1) {
                    curr = key;
                    break;
                }
            }

            if (curr == '0') {
                break;
            }

            int del = min(req, (cnt[curr] % 2 ? cnt[curr] - 1 : cnt[curr]));
            req -= del;
            cnt[curr] -= del;
            if (cnt[curr] == 0) {
                cnt.erase(curr);
            }
        }
        if (req == 0) {
            ans += 1;
        }
        else {
            break;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // vector<string> arr = {"xy", "tz", "abab"};
    vector<string> arr = {"pass", "sas", "asps", "df"};
    cout << countPalindromes(arr) << "\n";

    return 0;
}
