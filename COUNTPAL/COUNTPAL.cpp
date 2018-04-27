#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;
    vector<vector<bool>> palindrome(s.size(), vector<bool>(s.size() + 1));
    for(int i = 0; i < s.size(); i++) {
        palindrome[i][i] = true;
        palindrome[i][i + 1] = true;
    }
    for(int i = 2; i <= s.size(); i++) {
        for(int j = 0; j + i <= s.size(); j++) {
            if(s[j] == s[j + i - 1]) {
                palindrome[j][j + i] = palindrome[j + 1][j + i - 1];
            } else {
                palindrome[j][j + i] = false;
            }
        }
    }
    int dp[s.size() + 1];
    dp[s.size()] = 1;
    for(int i = s.size() - 1; i >= 0; i--) {
        dp[i] = 0;
        for(int j = i + 1; j <= s.size(); j++) {
            if(palindrome[i][j]) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }
    cout << dp[0];
    return 0;
}
