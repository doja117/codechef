#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    long long a[n], failed = n, success = 0;
    for(long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(long long i = 0; i < n && x >= (a[i] - 1) / 2 + 1; i++) {
        x -= (a[i] - 1) / 2 + 1;
        failed--;
    }
    for(long long i = 0; i < n - failed && x >= a[i] / 2; i++) {
        x -= a[i] / 2;
        success++;
    }
    cout << failed << ' ' << success;
    return 0;
}
