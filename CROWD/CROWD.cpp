#include <iostream>
#include <array>
using namespace std;

const long long MOD = 1000000007;

array<array<long long, 3>, 3> multiply(array<array<long long, 3>, 3>& a, array<array<long long, 3>, 3>& b) {
    array<array<long long, 3>, 3> result;
    for(auto i = 0; i < 3; i++) {
        for(auto j = 0; j < 3; j++) {
            result[i][j] = 0;
            for(auto k = 0; k < 3; k++) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

array<array<long long, 3>, 3> pow(array<array<long long, 3>, 3> x, long long n) {
    array<array<long long, 3>, 3> result {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};
    while(n > 0) {
        if(n % 2 == 1) {
            result = multiply(result, x);
        }
        x = multiply(x, x);
        n /= 2;
    }
    return result;
}

long long pow(long long x, long long n) {
    long long result = 1;
    while(n > 0) {
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
    for(long long n; cin >> n; ) {
        if(n == 1 || n == 2) {
            cout << 0 << endl;
        } else {
            array<array<long long, 3>, 3> m {{{1, 1, 1}, {1, 0, 0}, {0, 1, 0}}};
            m = pow(m, n - 2);
            cout << ((pow(2, n) - m[0][0] * 4 - m[0][1] * 2 - m[0][2]) % MOD + MOD) % MOD << endl;
        }
    }
    return 0;
}
