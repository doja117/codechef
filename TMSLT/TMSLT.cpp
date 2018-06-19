#include <iostream>
using namespace std;

const long long MOD = 1000000;

int main() {
    int T;
    cin >> T;
    for(long long n, a, b, c, d; cin >> n >> a >> b >> c >> d; ) {
        long long count[MOD + 1] = {}, s = d, result = 0;
        count[s]++;
        for(long long i = 1; i < n; i++) {
            s = (a * s * s + b * s + c) % MOD;
            count[s]++;
        }
        for(long long i = 0, j = 0; i <= MOD; i++) {
            while(count[i] > 0) {
                if(j % 2 == 0) {
                    result += i;
                } else {
                    result -= i;
                }
                count[i]--;
                j++;
            }
        }
        cout << abs(result) << endl;
    }
    return 0;
}
