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

int main() {
    int t;
    cin >> t;
    for(long long n, m, q, k; cin >> n >> m >> q >> k; cout << endl) {
        if(m <= q) {
            cout << 0;
        } else {
            cout << ((m - q) * (pow(q + 1, n) - 2 * pow(q, n) + pow(q - 1, n)) % MOD + MOD) % MOD;
        }
    }
    return 0;
}
