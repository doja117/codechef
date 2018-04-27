#include <iostream>
using namespace std;

const int SIZE = 1000001;

int main() {
    int t;
    cin >> t;
    long long prefix[2 * SIZE], digit[2 * SIZE], dp[SIZE];
    prefix[1] = 1;
    for(int i = 2; i < 2 * SIZE; i++) {
        digit[i] = 0;
        for(int j = i; j > 0; j /= 10) {
            if(j % 10 % 2 == 0) {
                digit[i] += j % 10;
            } else {
                digit[i] -= j % 10;
            }
        }
        digit[i] = abs(digit[i]);
        prefix[i] = prefix[i - 1] + digit[i];
    }
    for(int i = 1; i < SIZE; i++) {
        dp[i] = dp[i - 1] + 2 * (prefix[2 * i - 1] - prefix[i]) + digit[2 * i];
    }
    for(int n; cin >> n; cout << dp[n] << endl) {
    }
    return 0;
}
