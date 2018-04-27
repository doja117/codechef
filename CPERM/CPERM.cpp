#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long pow(long long x, long long n) {
    long long result = 1;
    while(n > 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        n /= 2;
        x = x * x % MOD;
    }
    return result;
}

long long negative(long long n) {
    return MOD - n;
}

int main() {
    int T;
    cin >> T;
    for(long long N; cin >> N; ) {
        if(N == 1) {
            cout << 0 << endl;
        } else {
            cout << (pow(2, N - 1) + negative(2)) % MOD << endl;
        }
    }
    return 0;
}
