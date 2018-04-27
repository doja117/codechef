#include <iostream>
#include <map>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int T;
    cin >> T;
    for(string S; cin >> S; ) {
        long long factorial[S.size() + 1], ifactorial[S.size() + 1], inv[S.size() + 1];
        inv[1] = 1;
        factorial[0] = 1;
        factorial[1] = 1;
        ifactorial[0] = 1;
        ifactorial[1] = 1;
        for(long long i = 2; i <= S.size(); i++) {
            inv[i] = (-MOD / i + MOD) * inv[MOD % i] % MOD;
            factorial[i] = factorial[i - 1] * i % MOD;
            ifactorial[i] = ifactorial[i - 1] * inv[i] % MOD;
        }
        auto result = factorial[S.size()];
        map<char, int> count;
        for(auto i : S) {
            count[i]++;
        }
        for(auto& i : count) {
            result = result * ifactorial[i.second] % MOD;
        }
        cout << result << endl;
    }
    return 0;
}
