#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    bool matrix[n][m];
    int dp[n];
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            matrix[i][j] = s[j] - '0';
        }
    }
    long long result = 0;
    dp[n - 1] = matrix[n - 1][0];
    result += dp[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        dp[i] = matrix[i][0];
        result += dp[i];
    }
    for(int j = 1; j < m; j++) {
        int count[n];
        count[n - 1] = matrix[n - 1][j];
        dp[n - 1] = min(dp[n - 1] + 1, count[n - 1]);
        result += dp[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            if(matrix[i][j]) {
                count[i] = count[i + 1] + 1;
            } else {
                count[i] = 0;
            }
            dp[i] = min(dp[i] + 1, count[i]);
            result += dp[i];
        }
    }
    cout << result;
    return 0;
}
