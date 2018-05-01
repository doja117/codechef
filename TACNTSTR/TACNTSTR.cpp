#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;
    int dp[s.size() + 1], result = 0;
    dp[0] = 1;
    for(int i = 1; i <= s.size(); i++) {
        int j = s[i - 1] - 'A';
        dp[i] = (dp[i - 1] * 26ll - j) % MOD;
        result = (result + dp[i - 1] * (25ll - j)) % MOD;
    }
    cout << result;
    return 0;
}
