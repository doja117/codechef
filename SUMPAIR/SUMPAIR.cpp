#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, d; cin >> n >> d; ) {
        long long a[n], result = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        for(int i = n - 1; i > 0; ) {
            if(a[i] - a[i - 1] < d) {
                result += a[i] + a[i - 1];
                i -= 2;
            } else {
                i--;
            }
        }
        cout << result << endl;
    }
    return 0;
}
