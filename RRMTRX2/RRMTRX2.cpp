#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = 10000007;

int main() {
    int n, m;
    cin >> n >> m;
    int sum[m];
    fill(sum, sum + m, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int A;
            cin >> A;
            sum[j] += A;
        }
    }
    long long result = 1;
    for(int i = 0; i < m; i++) {
        result = result * sum[i] % MOD;
    }
    result = (result + MOD) % MOD;
    cout << result;
    return 0;
}
