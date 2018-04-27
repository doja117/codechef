#include <iostream>
using namespace std;

const int MOD = 1000000000;

int main() {
    int T;
    cin >> T;
    for(int N, M; cin >> N >> M; ) {
        int dp[M + 1], C[2 * M][2 * M], sum[M + 1];
        for(int i = 1; i < 2 * M; i++) {
            C[i][0] = 1;
            C[i][i] = 1;
            for(int j = i - 1; j > 0; j--) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
        sum[0] = 1;
        dp[0] = 1;
        for(int i = 1; i <= M; i++) {
            dp[i] = C[i + M - 1][M - 1];
            sum[i] = (dp[i] + sum[i - 1]) % MOD;
        }
        for(int i = 1; i < N; i++) {
            dp[0] = 1;
            sum[0] = 1;
            for(int j = 1; j <= M; j++) {
                dp[j] = (long long)C[j + M - 1][M - 1] * sum[j] % MOD;
                sum[j] = (sum[j - 1] + dp[j]) % MOD;
            }
        }
        int result = 0;
        for(int i = 0; i <= M; i++) {
            result = (result + dp[i]) % MOD;
        }
        cout << result << endl;
    }
    return 0;
}
