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
    for(long long n; cin >> n; ) {
        long long result = pow(2, (n + 1) / 2);
        if(n % 2 == 0) {
            result = result + 2 * result + MOD - 2;
        } else {
            result = result + result + MOD - 2;
        }
        cout << result % MOD << endl;
    }
    return 0;
}
