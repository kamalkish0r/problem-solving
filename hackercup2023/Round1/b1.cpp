#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> primes;
// https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#sieving-till-root
void sieve() {
    int n = 1e5;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

vector<int> find_factors(int n) {
    vector<int> factors;
    for (int p : primes) {
        while (n % p == 0) {
            factors.push_back(p);
            n /= p;
        }
        if (p > n)
            break;
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

void solve() {
	int n; cin >> n;
    vector<int> factors = find_factors(n); 
    int sum = 0;
    for (int i : factors) {
        sum += i;
    }

    if (sum > 41) {
        cout << "-1\n";
        return;
    }
    
    int diff = 41 - sum;
    while (diff--) {
        factors.push_back(1);
    }
    cout << factors.size() << " ";
    for (int i : factors) {
        cout << i << " ";
    }
    cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("r.txt", "w", stderr);
#endif

    sieve();

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
    	cout << "Case #" << i << ": ";
    	solve();
    }


    return 0;
}