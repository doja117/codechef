#include <iostream>
using namespace std;

long long isqrt(long long n) {
    auto begin = 1ll, end = n;
    while(begin < end) {
        auto mid = (begin + end + 1) / 2;
        if(mid <= n / mid) {
            begin = mid;
        } else {
            end = mid - 1;
        }
    }
    return begin;
}

long long ceiling(long long a, long long b) {
    return (a - 1) / b + 1;
}

int main() {
    int T;
    cin >> T;
    for(long long N; cin >> N; ) {
        long long result = 0;
        for(long long a = 1; a <= ceiling(N, 2) - 1; a++) {
            long long ab = a * (N - a), c = isqrt(ab);
            if(c * c != ab) {
                c++;
            }
            for(long long c = 1; c * c < ab; c++) {
                result += ceiling(ab, c) - 1;
            }
            for(long long d = 1; d * d < ab; d++) {
                result += ceiling(ab, d) - c;
            }
        }
        result *= 2;
        if(N % 2 == 0) {
            long long ab = (N / 2) * (N / 2), c = isqrt(ab);
            if(c * c != ab) {
                c++;
            }
            for(long long c = 1; c * c < ab; c++) {
                result += ceiling(ab, c) - 1;
            }
            for(long long d = 1; d * d < ab; d++) {
                result += ceiling(ab, d) - c;
            }
        }
        cout << result << endl;
    }
    return 0;
}
