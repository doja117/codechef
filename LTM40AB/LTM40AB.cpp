#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long a, b, c, d; cin >> a >> b >> c >> d; ) {
        long long result = 0;
        for(long long x = a; x <= min(b, d - 1); x++) {
            result += d - max(c - 1, x);
        }
        cout << result << endl;
    }
    return 0;
}
