#include <bits/stdc++.h>
using namespace std;

// #define int long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(n + 1);
    ordered_set s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(i);
    }
    // for (int i = 1; i <= n; i++) {
    //     int index; cin >> index;
    //     auto it = s.find_by_order(index);
    //     // cout << *it << "\n";
    //     // s.erase(it);
    // }

    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/  

