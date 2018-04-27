#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string p;
    cin >> p;
    long long suffix[6][p.size() + 1];
    suffix[0][p.size()] = 0;
    suffix[2][p.size()] = 0;
    suffix[3][p.size()] = 0;
    suffix[5][p.size()] = 0;
    for(int i = p.size() - 1; i >= 0; i--) {
        suffix[0][i] = suffix[0][i + 1];
        suffix[2][i] = suffix[2][i + 1];
        suffix[3][i] = suffix[3][i + 1];
        suffix[5][i] = suffix[5][i + 1];
        suffix[p[i] - 'c'][i]++;
    }
    long long dp[6][6][p.size() + 1];
    for(char i : {0, 2, 3, 5}) {
        for(char j : {0, 2, 3, 5}) {
            if(i != j) {
                dp[i][j][p.size()] = 0;
                for(int k = p.size() - 1; k >= 0; k--) {
                    dp[i][j][k] = dp[i][j][k + 1];
                    if(p[k] == i + 'c') {
                        dp[i][j][k] += suffix[j][k];
                    }
                }
            }
        }
    }
    int q, l, r;
    cin >> q;
    for(string a, b; cin >> a >> b >> l >> r; ) {
        auto i = a.front() - 'c', j = b.front() - 'c';
        auto result = dp[i][j][l - 1] - dp[i][j][r];
        result -= (suffix[i][l - 1] - suffix[i][r]) * suffix[j][r];
        cout << result << '\n';
    }
    return 0;
}
