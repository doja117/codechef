#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while(b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int T;
    cin >> T;
    for(long long n; cin >> n; cout << endl) {
        long long a[n], result[n + 1], prefix[n];
        cin >> a[0];
        prefix[0] = a[0];
        for(long long i = 1; i < n; i++) {
            cin >> a[i];
            prefix[i] = prefix[i - 1] + a[i];
            result[i] = 0;
        }
        result[n] = 0;
        for(long long i = 0; i < n; i++) {
            auto g = gcd(prefix[i], prefix[n - 1]), q = prefix[n - 1] / g;
            for(long long j = q; j <= n; j += q) {
                result[j]++;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(result[i] == i) {
                cout << '1';
            } else {
                cout << '0';
            }
        }
    }
    return 0;
}
