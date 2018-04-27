#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int T;
    cin >> T;
    for(long long n, d; cin >> n >> d; ) {
        long long y[n + n];
        d *= d;
        for(long long i = 1; i <= n; i++) {
            y[i - 1] = i * d;
        }
        for(long long i = n + 1; i < n + n; i++) {
            y[i - 1] = (n - i + n) * d;
        }
        y[n + n - 1] = 0;
        for(long long i = 0; i < n + n - 1; i++) {
            y[i + 1] += y[i] / 10;
            y[i] = y[i] % 10;
        }
        long long result = 0, i = n + n - 1;
        while(y[i] == 0) {
            i--;
        }
        for(long long p = 1; i >= 0; i--, p = p * 23 % MOD) {
            result = (result + y[i] * p) % MOD;
        }
        cout << result << endl;
    }
    return 0;
}
