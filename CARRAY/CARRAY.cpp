#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long n, k, b; cin >> n >> k >> b; ) {
        long long a[n], result = 1;
        for(long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        for(long long i = 1, j = 0; i < n; i++) {
            if(a[i] >= k * a[j] + b) {
                j = i;
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
