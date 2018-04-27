#include <iostream>
using namespace std;
 
const long long MOD = 1000003;

long long pow(long long x, long long n) {
    long long result = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        n /= 2;
        x = x * x % MOD;
    }
    return result;
}

long long inverse(long long n) {
    return pow(n, MOD - 2);
}

long long C(long long n, long long k) {
    long long top = 1, bottom = 1;
    for(long long i = 1; i <= k; i++) {
        top = top * (n + 1 - i) % MOD;
        bottom = bottom * i % MOD;
    }
    return top * inverse(bottom) % MOD;
}

int main() {
    int T;
    cin >> T;
    for(long long N, L, R; cin >> N >> L >> R; ) {
        long long result = 1;
        for(long long n = R - L + N + 1, k = N, p = MOD; k > 0; n /= p, k /= p, p = p * MOD) {
            result = result * C(n % p, k % p) % MOD;
        }
        cout << (result + MOD - 1) % MOD << endl;
    }
    return 0;
}
