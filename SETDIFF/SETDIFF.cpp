#include <iostream>
#include <algorithm>
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
    for(int n; cin >> n; ) {
        long long s[n], result = 0;
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        sort(s, s + n);
        for(int i = 0; i < n; i++) {
            result = (result + s[i] * (pow(2, i) - pow(2, n - i - 1) + MOD)) % MOD;
        }
        cout << result << endl;
    }
    return 0;
}
