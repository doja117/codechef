#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        int a[n][n];
        long long result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
            sort(a[i], a[i] + n);
        }
        for(int i = n - 1, current = a[n - 1][n - 1] + 1; i >= 0; i--) {
            auto it = lower_bound(a[i], a[i] + n, current);
            if(it == a[i]) {
                result = -1;
                break;
            } else {
                current = *prev(it);
                result += current;
            }
        }
        cout << result << endl;
    }
    return 0;
}
