long long binpowm(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int inverse(int a, int b) {
    return binpowm(a, b - 2, b)
}

vector<int> factorial, ifactorial;
int MAXN = 1e5 + 5;
void pre_factorial(int m) {
    factorial.resize(MAXN + 1);
    ifactorial.resize(MAXN + 1);
    factorial[0] = 1;
    ifactorial[0] = inverse(factorial[0], m);
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = i * factorial[i - 1] % m;
        ifactorial[i] = inverse(factorial[i], m);
    }
}

int nCr_mod_m(int n, int r, int m) {
    if (factorial.empty()) {
        pre_factorial(m);
    }

    return factorial[n] * ifactorial[r] % m * ifactorial[n - r] % m;
}