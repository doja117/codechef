#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long pow(long long x, long long n) {
    long long result = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        x = x * x % MOD;
        n /= 2;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        int a[n], max = 0, count;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] > max) {
                max = a[i];
                count = 1;
            } else if(a[i] == max) {
                count++;
            }
        }
        cout << (pow(2, count) + MOD - 1) % MOD << endl;
    }
    return 0;
}
