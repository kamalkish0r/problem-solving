// https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#sieving-till-root
vector<int> primes;
void sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
        }
    }
}

// https://cp-algorithms.com/algebra/factorial-divisors.html#prime-k
int fact_pow_prime(int n, int k) {
    int res = 0;
    while (n) {
        n /= k;
        res += n;
    }
    return res;
}

int fact_pow(int n, int k) {
    if (primes.empty()) { 
        sieve(1e5 + 5); // check value of parameter
    }
    // find prime factors of k
    map<int, int> cnt;
    int N = n;
    for (int prime : primes) {
        while (n % prime == 0) {
            cnt[prime]++;
            n /= prime;
        }
        if (n < prime) {
            if (n > 1) {
                cnt[n]++;
            }
            break;
        }
    }

    n = N;
    int res = INT_MAX;
    for (auto [ki, pi] : cnt) {
        res = min(res, fact_pow_prime(n, ki) / pi);
    }

    return res;
}