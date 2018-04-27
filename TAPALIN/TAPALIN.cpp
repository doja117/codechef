#include <iostream>
using namespace std;

const long long MOD = 1000000007;

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

int main() {
    int T;
    cin >> T;
    for(long long N; cin >> N; ) {
        auto t = pow(26, N / 2 + 1), result = 2 * ((t + MOD - 1) % MOD * inverse(25) + MOD - 1) % MOD;
        if(N % 2 == 1) {
            result = (result + t) % MOD;
        }
        cout << result << endl;
    }
    return 0;
}
