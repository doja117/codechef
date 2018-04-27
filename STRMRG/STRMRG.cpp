#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, m; cin >> n >> m; ) {
        string a, b;
        cin >> a >> b;
        int dp[n + 1][m + 1][2];
        dp[n][m][0] = 0;
        dp[n][m][1] = 0;
        for(int j = m - 1; j >= 0; j--) {
            dp[n][j][0] = dp[n][j + 1][0];
            if(b[j] != b[j + 1]) {
                dp[n][j][0]++;
            }
            dp[n][j][1] = dp[n][j][0];
        }
        for(int i = n - 1; i >= 0; i--) {
            dp[i][m][0] = dp[i + 1][m][0];
            if(a[i] != a[i + 1]) {
                dp[i][m][0]++;
            }
            dp[i][m][1] = dp[i][m][0];
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                auto t1 = dp[i + 1][j][0], t2 = dp[i + 1][j][1];
                if(a[i] != a[i + 1]) {
                    t1++;
                }
                if(a[i] != b[j]) {
                    t2++;
                }
                dp[i][j][0] = min(t1, t2);
                t1 = dp[i][j + 1][0], t2 = dp[i][j + 1][1];
                if(b[j] != a[i]) {
                    t1++;
                }
                if(b[j] != b[j + 1]) {
                    t2++;
                }
                dp[i][j][1] = min(t1, t2);
            }
        }
        cout << min(dp[0][0][0], dp[0][0][1]) << endl;
    }
    return 0;
}
