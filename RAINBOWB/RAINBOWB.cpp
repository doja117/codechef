#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    long long n;
    cin >> n;
    long long size = (n - 1) / 2, factorial[size], inv[size], ifactorial[size];
    factorial[0] = 1;
    ifactorial[0] = 1;
    factorial[1] = 1;
    ifactorial[1] = 1;
    inv[1] = 1;
    for(long long i = 2; i < size; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        ifactorial[i] = inv[i] * ifactorial[i - 1] % MOD;
    }
    long long result = 0;
    for(long long i = 5; i < size; i++) {
        result = (result + factorial[i] * ifactorial[5] % MOD * ifactorial[i - 5]) % MOD;
    }
    cout << result;
    return 0;
}
