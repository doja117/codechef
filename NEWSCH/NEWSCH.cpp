#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long pow(long long x, int n) {
    long long result = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            result = (result * x) % MOD;
        }
        x = x * x % MOD;
        n /= 2;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        auto result = pow(3, n);
        if(n % 2 == 1) {
            result = (result + MOD - 3) % MOD;
        } else {
            result = (result + 3) % MOD;
        }
        cout << result << endl;
    }
    return 0;
}
