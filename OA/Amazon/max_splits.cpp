#include <bits/stdc++.h>
using namespace std;

#define int long long

int get_max_splits(string s, int k) {
    map<char, int> suffix_cnt;
    for (char ch : s) 
        suffix_cnt[ch]++;

    int splits = 0;
    map<char, int> prefix_cnt;
    for (int i = 0; i < s.size(); i++) {
        prefix_cnt[s[i]]++;
        suffix_cnt[s[i]]--;
        if (suffix_cnt[s[i]] == 0) {
            suffix_cnt.erase(s[i]);
        }

        splits += (prefix_cnt.size() > k and suffix_cnt.size() > k);
    }

    return splits;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s = "adbccdbada";
    int k = 2;
    cout << get_max_splits(s, k) << "\n";

    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/  



