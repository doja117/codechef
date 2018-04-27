#include <iostream>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, r; cin >> n >> r; ) {
        string result = "YES\n";
        for(int i = 0, left = INT_MIN, right = INT_MAX, a; i < n; i++) {
            cin >> a;
            if(a < left || a > right) {
                result = "NO\n";
            }
            if(a > r) {
                right = min(right, a);
            } else {
                left = max(left, a);
            }
        }
        cout << result;
    }
    return 0;
}
