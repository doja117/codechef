#include <iostream>
using namespace std;

long long C(long long n, long long k) {
    long long result = 1;
    if(k > n - k) {
        k = n - k;
    }
    for(long long i = 1; i <= k; i++) {
        result = result * (n + 1 - i) / i;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    for(long long n, k; cin >> n >> k; cout << C(n - 1, k - 1) << endl) {
    }
    return 0;
} 
