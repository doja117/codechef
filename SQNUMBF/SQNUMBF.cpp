#include <iostream>
using namespace std;

long long isqrt(long long n) {
    auto begin = 0ll, end = n;
    while(begin < end) {
        auto mid = (end + begin + 1) / 2;
        if(mid <= n / mid) {
            begin = mid;
        } else {
            end = mid - 1;
        }
    }
    return end;
}

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
    for(int N; cin >> N; ) {
        long long A[N], result;
        for(int i = 0; i != N; i++) {
            cin >> A[i];
        }
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                auto p = gcd(A[i], A[j]);
                if(p > 1) {
                    result = p;
                    goto next;
                }
            }
            for(long long p = 2; p * p <= A[i] / p; p++) {
                if(A[i] % (p * p) == 0) {
                    result = p;
                    goto next;
                }
            }
            for(long long j = 2; j * j <= A[i] / j; j++) {
                if(A[i] % j == 0) {
                    auto p = isqrt(A[i] / j);
                    if(p * p == A[i] / j) {
                    	result = p;
                    	goto next;
                    }
                }
            }
            auto p = isqrt(A[i]);
            if(p * p == A[i] && p > 1) {
                result = p;
            }
        }
        next:
        cout << result << endl;
    }
    return 0;
}
