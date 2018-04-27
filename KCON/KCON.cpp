#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, k; cin >> n >> k; ) {
        int a[n];
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        long long result = a[0], dp = a[0], prefix = a[0], c2 = a[0], suffix = a[n - 1], c3 = a[n - 1];
        for(int i = 1; i < n; i++) {
            dp += a[i];
            prefix += a[i];
            if(c2 < prefix) {
                c2 = prefix;
            }
            if(dp < a[i]) {
                dp = a[i];
            }
            if(dp > result) {
                result = dp;
            }
        }
        for(int i = n - 2; i >= 0; i--) {
            suffix += a[i];
            if(c3 < suffix) {
                c3 = suffix;
            }
        }
        if(k > 1) {
            result = max(result, c2 + max(0ll, sum * (k - 2)) + c3);
        }
        cout << result << endl;
    }
    return 0;
}
