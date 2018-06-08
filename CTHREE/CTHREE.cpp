#include <iostream>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, a, b, c; cin >> n >> a >> b >> c; ) {
        int result = 0;
        set<int> divisor;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                divisor.emplace(i);
                divisor.emplace(n / i);
            }
        }
        for(auto i : divisor) {
            if(i > a) {
                break;
            }
            for(auto j : divisor) {
                if(j > min(b, n / i)) {
                    break;
                }
                auto k = n / (i * j);
                if(k <= c && n == i * j * k) {
                    result++;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
