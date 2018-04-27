#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int SIZE = 1000000000;
map<tuple<int, int, int>, int> dp;

int solve(vector<int>& f, int x, int k, int n) {
    if(k == 0) {
        if(x == 0) {
            return 1;
        }
        return 0;
    }
    if(x == 0 || n == 0) {
        return 0;
    }
    tuple<int, int, int> key = {x, k, n};
    auto find = dp.find(key);
    if(find != end(dp)) {
        return find->second;
    }
    int result = solve(f, x, k, n - 1);
    if(x >= f[n - 1] && x <= (long long)k * f[n - 1]) {
        result += solve(f, x - f[n - 1], k - 1, n);
    }
    dp[key] = result;
    return result;
}
 
int main() {
    int Q;
    cin >> Q;
    vector<int> f;
    f.emplace_back(1);
    f.emplace_back(2);
    for(int next = f.back() + f[f.size() - 2]; next <= SIZE; next = f.back() + f[f.size() - 2]) {
        f.emplace_back(next);
    }
    for(int X, K; cin >> X >> K; ) {
        cout << solve(f, X, K, f.size()) << endl;
    }
    return 0;
}
