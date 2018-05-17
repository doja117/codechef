#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        long long result = 0;
        for(long long p, q, d; n > 0; n--) {
            cin >> p >> q >> d;
            result += p * q * d * d;
        }
        printf("%lld.%.4lld\n", result / 10000, result % 10000);
    }
    return 0;
}
