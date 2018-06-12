#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 10001;

long long ceiling(long long a, long long b) {
    return (a - 1) / b + 1;
}

int main() {
    int T;
    cin >> T;
    vector<bool> prime(SIZE, true);
    prime[1] = false;
    for(int i = 2; i * i < SIZE; i++) {
        if(prime[i]) {
            for(int j = i * i; j < SIZE; j += i) {
                prime[j] = false;
            }
        }
    }
    for(long long l, r; cin >> l >> r; ) {
        int divisor[r - l + 1], result = 0;
        fill(divisor, divisor + r - l + 1, 0);
        for(long long i = 1; i * i <= r; i++) {
            if(i * i >= l) {
                divisor[i * i - l] += 1;
            }
            for(long long j = i * i + max(ceiling(l - i * i, i) * i, i); j <= r; j += i) {
                divisor[j - l] += 2;
            }
        }
        for(long long i = l; i <= r; i++) {
            if(prime[divisor[i - l]]) {
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
