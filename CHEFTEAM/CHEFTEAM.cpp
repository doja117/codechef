#include <iostream>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while(b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

unsigned long long c(unsigned long long n, unsigned long long k) {
    if(k > n) {
        return 0;
    }
    if(n - k < k) {
        k = n - k;
    }
    unsigned long long result = 1;
    for(unsigned long long i = 1; i <= k; i++) {
        auto d = gcd(result, i);
        result /= d;
        result *= (n + 1 - i) / (i / d);
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    for(unsigned long long n, k; cin >> n >> k; cout << c(n, k) << endl) {
    }
    return 0;
}
