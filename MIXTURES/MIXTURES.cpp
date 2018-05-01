#include <iostream>
#include <climits>
using namespace std;

int main() {
    for(int n; cin >> n; ) {
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int prefix[n + 1];
        prefix[0] = 0;
        for(int i = 1; i <= n; i++) {
            prefix[i] = (prefix[i - 1] + a[i - 1]) % 100;
        }
        int dp[n][n];
        for(int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n - i; j++) {
                dp[j][j + i] = INT_MAX;
                for(int k = j; k < i + j; k++) {
                    dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + (prefix[k + 1] - prefix[j] + 100) % 100 * ((prefix[j + i + 1] - prefix[k + 1] + 100) % 100));
                }
            }
        }
        cout << dp[0][n - 1] << endl;
    }
    return 0;
}
