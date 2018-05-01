#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int T;
    cin >> T;
    for(long long n, k; cin >> n >> k; ) {
        long long dp[n + 1];
        for(long long i = 0; i < k; i++) {
            dp[i] = 1;
        }
        for(long long i = k; i <= n; i++) {
            dp[i] = (dp[i - k] + dp[i - 1]) % MOD;
        }
        cout << dp[n] << endl;
    }
    return 0;
}
