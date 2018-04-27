#include <iostream>
using namespace std;

long long pow(long long x, long long n) {
    long long result = 1;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x;
        }
        n /= 2;
        x = x * x;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    for(long long N; cin >> N; ) {
        long long result = 1;
        for(long long d = 2; d * d <= N; d++) {
            long long n = 1;
            while(N % d == 0) {
                n++;
                N /= d;
            }
            result *= (pow(d, n) - 1) / (d - 1);
        }
        if(N > 1) {
            result *= N + 1;
        }
        cout << result << endl;
    }
    return 0;
} 
