#include <iostream>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long n; cin >> n; ) {
        long long a[n], prefix[n + 1], suffix[n + 1], result = INT_MIN;
        for(long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        prefix[0] = 0;
        for(long long i = 1; i <= n; i++) {
            prefix[i] = max(prefix[i - 1] + a[i - 1], a[i - 1]);
            result = max(result, prefix[i]);
        }
        suffix[n] = 0;
        for(long long i = n - 1; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1] + a[i], a[i]);
        }
        for(long long i = 1; i < n; i++) {
            result = max(result, prefix[i - 1] + suffix[i]);
        }
        cout << result << endl;
    }
    return 0;
}
