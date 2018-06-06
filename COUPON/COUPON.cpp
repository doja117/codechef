#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, m; cin >> n >> m; ) {
        int cost[n][m], discount[n][m];
        long long dp[n][m], prev = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> cost[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> discount[i][j];
            }
        }
        for(int j = 0; j < m; j++) {
            dp[n - 1][j] = cost[n - 1][j];
            prev = min(prev, dp[n - 1][j]);
        }
        for(int i = n - 2; i >= 0; i--) {
            auto current = LLONG_MAX;
            for(int j = 0; j < m; j++) {
                dp[i][j] = cost[i][j] + min(dp[i + 1][j] - min(discount[i][j], cost[i + 1][j]), prev);
                current = min(current, dp[i][j]);
            }
            prev = current;
        }
        cout << *min_element(dp[0], dp[0] + m) << endl;
    }
    return 0;
}
