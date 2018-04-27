#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(long long k, d0, d1; cin >> k >> d0 >> d1; ) {
        long long t = d0 + d1;
        long long sum = 2 * t % 10 + 4 * t % 10 + 8 * t % 10 + 6 * t % 10;
        long long partial[] = {0, 2 * t % 10, 2 * t % 10 + 4 * t % 10, 2 * t % 10 + 4 * t % 10 + 8 * t % 10};
        long long result = t;
        if(k > 2) {
            result += t % 10;
        }
        if(k >= 3) {
            result += (k - 3) / 4 * sum + partial[(k - 3) % 4];
        }
        if(result % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
