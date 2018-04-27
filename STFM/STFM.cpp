#include <iostream>
using namespace std;

unsigned long long* precompute;

unsigned long long f(unsigned long long x, unsigned long long m) {
    unsigned long long result = precompute[min(x, m - 1)];
    if(x % 2 == 0) {
        result = (result + (x % m) * ((x / 2) % m) % m * ((x + 1) % m)) % m;
    } else {
        result = (result + (x % m) * (x % m) % m * (((x + 1) / 2) % m)) % m;
    }
    return result;
}

int main() {
    unsigned long long n, m, result = 0;
    cin >> n >> m;
    precompute = new unsigned long long[m];
    precompute[0] = 1;
    for(unsigned long long i = 1; i < m; i++) {
        precompute[i] = precompute[i - 1] * i % m;
    }
    for(unsigned long long i = 2; i < m; i++) {
        precompute[i] = (precompute[i] * i % m + precompute[i - 1]) % m;
    }
    for(unsigned long long p; cin >> p; result = (result + f(p, m)) % m) {
    }
    cout << result;
    return 0;
}
