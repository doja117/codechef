#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        int A[N];
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        array<long long, 2> dp = {A[0], A[0]};
        for(int i = 1; i < N; i++) {
            dp = {max({dp[0] + A[i], dp[0] - A[i], dp[0] * A[i], dp[1] * A[i]}), min({dp[1] - A[i], dp[1] + A[i], dp[0] * A[i], dp[1] * A[i]})};
        }
        cout << dp[1] << endl;
    }
    return 0;
} 
