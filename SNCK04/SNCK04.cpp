#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 1000001;

int main() {
    int t;
    cin >> t;
    long long dp[SIZE];
    vector<bool> prime(SIZE, true);
    for(int i = 0; i < SIZE; i++) {
        dp[i] = i;
    }
    for(int i = 2; i < SIZE; i++) {
        if(prime[i]) {
            for(int j = i; j < SIZE; j += i) {
                prime[j] = false;
                dp[j] = (i - 1) * dp[j] / i;
            }
        }
    }
    for(int i = 3; i < SIZE; i++) {
        dp[i] += dp[i - 1];
    }
    for(int n; cin >> n; cout << dp[n] << endl) {
    }
    return 0;
}
