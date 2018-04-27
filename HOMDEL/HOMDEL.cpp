#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    int dp[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> dp[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                if(dp[j][k] > dp[j][i] + dp[i][k]) {
                    dp[j][k] = dp[j][i] + dp[i][k];
                }
            }
        }
    }
    cin >> M;
    for(int S, G, D; cin >> S >> G >> D; ) {
        cout << dp[S][G] + dp[G][D] << ' ' << dp[S][G] + dp[G][D] - dp[S][D] << endl;
    }
    return 0;
}
