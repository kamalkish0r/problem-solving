#include <bits/stdc++.h>
using namespace std;

#define int long long

void prime_factors(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			cout << i << " ";
			while (n  % i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1) {
		cout << n;
	}
	cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int cnt = 0;
    for (int i = 2; i <= 100; i++) {
    	// int n = i;
    	// bool prime = true;
    	// for (int j = 2; j * j <= n; j++) {
    	// 	while(n % j == 0) {
    	// 		prime = false;
    	// 		n /= j;
    	// 	}
    	// }

    	// prime &= (n == i);
    	// if (prime) {
    	// 	cnt++;
    	// 	cout << i << ", ";
    	// }

    	prime_factors(i);
    } 

    cout << "\n" << cnt;

    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/  

