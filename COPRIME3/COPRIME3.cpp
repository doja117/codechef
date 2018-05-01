#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 1000001;

long long C3(long long n) {
    return n * (n - 1) * (n - 2) / 6;
}

int main() {
    int mobius[SIZE], N, a[SIZE], count[SIZE];
    fill(mobius, mobius + SIZE, 0);
    fill(a, a + SIZE, 0);
    cin >> N;
    for(int i; cin >> i; a[i]++) {
    }
    mobius[1] = 1;
    for(int i = 1; i < SIZE; i++) {
        for(int j = i + i; j < SIZE; j += i) {
            mobius[j] -= mobius[i];
        }
        count[i] = 0;
        for(int j = i; j < SIZE; j += i) {
            count[i] += a[j];
        }
    }
    long long result = 0;
    for(int i = 1; i < SIZE; i++) {
        result += mobius[i] * C3(count[i]);
    }
    cout << result;
    return 0;
}
