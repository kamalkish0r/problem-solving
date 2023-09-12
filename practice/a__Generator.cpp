#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    srand(time(0));
    // cout << "1\n";
    int n = 1 + rand() % 7;
    int m = 1 + rand() % 7;
    cout << n  << " " << m << "\n";

    int b = rand() % (n * m);
    cout << b << "\n";
    set<pair<int, int>> broken;
    while (broken.size() < b) {
    	int i = rand() % n, j = rand() % m;
    	broken.insert({i, j});
    }

    for (auto it : broken) {
    	cout << it.first << " " << it.second << "\n";
    }

    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/  

