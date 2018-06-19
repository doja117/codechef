#include <iostream>
using namespace std;

const long long MOD = 1000000007;

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
    int T;
    cin >> T;
    for(long long n; cin >> n; cout << (pow(2, n) - 1 + MOD) % MOD << endl) {
    }
    return 0;
}
