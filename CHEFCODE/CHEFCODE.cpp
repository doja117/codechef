#include <iostream>
using namespace std;

long long solve(long long* a, long long n, long long k) {
    if(k == 0) {
        return 0;
    }
    if(n == 0) {
        return 1;
    }
    if(a[n - 1] == 1) {
        return solve(a, n - 1, k) * 2;
    } else {
        return solve(a, n - 1, k) + solve(a, n - 1, k / a[n - 1]);
    }
}

int main() {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for(int i = 0; cin >> a[i]; i++) {
    }
    cout << solve(a, n, k) - 1;
    return 0;
}
