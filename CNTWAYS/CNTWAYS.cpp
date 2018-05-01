#include <iostream>
using namespace std;

const long long MOD = 1000000007;
const long long SIZE = 800001;
long long FACTORIAL[SIZE], IFACTORIAL[SIZE];

void precompute() {
    long long inv[SIZE];
    inv[1] = 1;
    FACTORIAL[0] = 1;
    FACTORIAL[1] = 1;
    IFACTORIAL[0] = 1;
    IFACTORIAL[1] = 1;
    for(auto i = 2ll; i < SIZE; i++) {
        inv[i] = (-MOD / i + MOD) * inv[MOD % i] % MOD;
        FACTORIAL[i] = FACTORIAL[i - 1] * i % MOD;
        IFACTORIAL[i] = IFACTORIAL[i - 1] * inv[i] % MOD;
    }
}

long long C(long long n, long long m) {
    return FACTORIAL[n] * IFACTORIAL[m] % MOD * IFACTORIAL[n - m] % MOD;
}

int main() {
    precompute();
    int r;
    cin >> r;
    for(long long n, m, a, b; cin >> n >> m >> a >> b; ) {
        long long result = C(n + m, n);
        for(long long i = 0; i < b; i++) {
            result = (result - C(n - a + i, i) * C(m - i + a - 1, a - 1)) % MOD;
        }
        cout << (result + MOD) % MOD << endl;
    }
    return 0;
}
