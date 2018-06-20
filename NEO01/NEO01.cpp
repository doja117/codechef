#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        long long a[n + 1], result = LLONG_MIN;
        a[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        for(int i = 1; i <= n; i++) {
            a[i] += a[i - 1];
        }
        for(int i = 0; i <= n; i++) {
            result = max(result, a[i] + (a[n] - a[i]) * (n - i));
        }
        cout << result << endl;
    }
    return 0;
}
