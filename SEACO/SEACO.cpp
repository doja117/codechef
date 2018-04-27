#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int main() {
    int t;
    cin >> t;
    for(int n, m; cin >> n >> m; cout << endl) {
        int queries[m + 1], result[n + 1];
        bool type[m];
        pair<int, int> interval[m];
        fill(queries, queries + m + 1, 0);
        for(int i = 0, j; i < m; i++) {
            cin >> j >> interval[i].first >> interval[i].second;
            type[i] = j == 1;
        }
        if(!type[m - 1]) {
            queries[interval[m - 1].first - 1]--;
            queries[interval[m - 1].second]++;
        }
        queries[m] = 1;
        for(int i = m - 2; i >= 0; i--) {
            queries[i + 1] = (queries[i + 1] + queries[i + 2]) % MOD;
            if(!type[i]) {
                queries[interval[i].first - 1] = (queries[interval[i].first - 1] - queries[i + 1] + MOD) % MOD;
                queries[interval[i].second] = (queries[interval[i].second] + queries[i + 1]) % MOD;
            }
        }
        fill(result, result + n, 0);
        for(int i = 0; i < m; i++) {
            if(type[i]) {
                result[interval[i].first - 1] = (result[interval[i].first - 1] + queries[i + 1]) % MOD;
                result[interval[i].second] = (result[interval[i].second] + MOD - queries[i + 1]) % MOD;
            }
        }
        cout << result[0] << ' ';
        for(int i = 1; i < n; i++) {
            result[i] = (result[i] + result[i - 1]) % MOD;
            cout << result[i] << ' ';
        }
    }
    return 0;
}
