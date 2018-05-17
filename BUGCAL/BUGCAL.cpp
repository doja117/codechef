#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int a, b; cin >> a >> b; ) {
        int result = 0;
        for(int exp = 1; a > 0 || b > 0; a /= 10, b /= 10, exp *= 10) {
            result += (a % 10 + b % 10) % 10 * exp;
        }
        cout << result << endl;
    }
    return 0;
}
