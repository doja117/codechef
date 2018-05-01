#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void cal(long long* dp, vector<int>* v, int sum, int k) {
    for(int i = v[0].size() - 1, j = v[1].size() - 1; k <= sum; k += 2) {
        auto c1 = dp[k - 2], c2 = dp[k - 2], one = 0ll, two = 0ll;
        if(i >= 1) {
            c1 += v[0][i] + v[0][i - 1];
            one = 2;
        } else if(i >= 0) {
            c1 += v[0][i];
            one = 1;
        }
        if(j >= 0) {
            c2 += v[1][j];
            two = 1;
        }
        if(c1 < c2) {
            dp[k] = c2;
            j -= two;
        } else {
            dp[k] = c1;
            i -= one;
        }
    }
}
 
int main() {
    int n, sum = 0;
    cin >> n;
    vector<int> v[2];
    for(int w, c; cin >> w >> c; v[w - 1].emplace_back(c)) {
        sum += w;
    }
    sort(begin(v[0]), end(v[0]));
    sort(begin(v[1]), end(v[1]));
    long long dp[sum + 1];
    dp[0] = 0;
    cal(dp, v, sum, 2);
    if(!v[0].empty()) {
        dp[1] = v[0].back();
        v[0].pop_back();
    } else {
        dp[1] = 0;
    }
    cal(dp, v, sum, 3);
    for(int i = 1; i <= sum; i++) {
        cout << dp[i] << ' ';
    }
    return 0;
}
