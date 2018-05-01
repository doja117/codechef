#include <iostream>
using namespace std;

const int SIZE = 1000001;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        int dp[SIZE][32];
        for(int i = 0; i < SIZE; i++) {
            dp[i][0] = 0;
        }
        for(int i = 0, a; i < n; i++) {
            cin >> a;
            dp[a][0]++;
        }
        for(int i = 0; i < SIZE; i++) {
            for(int j = 1; j < 32; j++) {
                if(i & (1 << (j - 1))) {
                    dp[i][j] = dp[i][j - 1] + dp[i ^ (1 << (j - 1))][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        long long result = 0;
        for(int i = 0; i < SIZE; i++) {
            result += dp[i][0] * (dp[i][31] - dp[i][0]) + dp[i][0] * (dp[i][0] - 1ll) / 2;
        }
        cout << result << endl;
    }
    return 0;
}
