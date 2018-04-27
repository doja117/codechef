#include <iostream>
using namespace std;

long long MOD = 1000000007;
long long* factorial, *ifactorial;

void precompute(long long n) {
    factorial = new long long[n + 1];
    ifactorial = new long long[n + 1];
    long long inv[n + 1];
    inv[1] = 1;
    factorial[0] = 1;
    factorial[1] = 1;
    ifactorial[0] = 1;
    ifactorial[1] = 1;
    for(auto i = 2ll; i <= n; i++) {
        inv[i] = (-MOD / i + MOD) * inv[MOD % i] % MOD;
        factorial[i] = factorial[i - 1] * i % MOD;
        ifactorial[i] = ifactorial[i - 1] * inv[i] % MOD;
    }
}

long long C(long long n, long long m) {
    return factorial[n] * ifactorial[m] % MOD * ifactorial[n - m] % MOD;
}

long long pow(long long x, long long n) {
    long long result = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        x = x * x % MOD;
        n /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    for(long long n, k; cin >> n >> k; ) {
        precompute(n);
        long long nonzero = 0, result = 0;
        for(long long i = 0, a; i < n; i++) {
            cin >> a;
            if(a != 0) {
                nonzero++;
            }
        }
        if(nonzero == n) {
            while(k >= 0) {
                if(k <= nonzero) {
                    result = (result + C(nonzero, k)) % MOD;
                }
                k -= 2;
            }
        } else {
            while(k >= 0) {
                if(k <= nonzero) {
                    result = (result + C(nonzero, k)) % MOD;
                }
                k--;
            }
        }
        cout << result << endl;
    }
    return 0;
}
