#include <iostream>
using namespace std;

const long long MOD = 1000000007, SIZE = 2000002;
long long *FACTORIAL, *IFACTORIAL;

void precompute() {
    FACTORIAL = new long long[SIZE], IFACTORIAL = new long long[SIZE];
    long long inv[SIZE];
    FACTORIAL[0] = 1;
    IFACTORIAL[0] = 1;
    inv[1] = 1;
    FACTORIAL[1] = 1;
    IFACTORIAL[1] = 1;
    for(auto i = 2; i < SIZE; i++) {
        FACTORIAL[i] = FACTORIAL[i - 1] * i % MOD;
        inv[i] = (-MOD / i + MOD) * inv[MOD % i] % MOD;
        IFACTORIAL[i] = IFACTORIAL[i - 1] * inv[i] % MOD;
    }
}

long long C(long long n, long long k) {
    return FACTORIAL[n] * IFACTORIAL[k] % MOD * IFACTORIAL[n - k] % MOD;
}

int main() {
    int T;
    cin >> T;
    precompute();
    for(long long n, k; cin >> n >> k; cout << (2 * C(n + k + 1, k + 2) + MOD - n) % MOD << endl) {
    }
    return 0;
}
