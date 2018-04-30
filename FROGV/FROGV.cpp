#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    pair<int, int> a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    int dp[n];
    dp[a[0].second] = 0;
    for(int i = 1; i < n; i++) {
        if(a[i].first - a[i - 1].first <= k) {
            dp[a[i].second] = dp[a[i - 1].second];
        } else {
            dp[a[i].second] = i;
        }
    }
    for(int i, j; cin >> i >> j; ) {
        if(dp[i - 1] == dp[j - 1]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
