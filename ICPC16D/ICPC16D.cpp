#include <iostream>
using namespace std;

const int SIZE = 750001, MOD = 1000000007;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; ) {
        bool map[SIZE] = {};
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            map[a]++;
        }
        int dp[SIZE] = {}, result = 0;
        for(int i = SIZE - 1; i >= 1; i--) {
            if(map[i]) {
                dp[i] = 1;
                for(int j = 2 * i; j < SIZE; j += i) {
                    dp[i] = (dp[i] + dp[j]) % MOD;
                }
                result = (result + dp[i]) % MOD;
            }
        }    
        cout << result << endl;
    }
    return 0;
}
