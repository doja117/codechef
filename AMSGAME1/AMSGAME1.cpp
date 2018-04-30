#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        int result = 0;
        for(int j; n > 0; n--) {
            cin >> j;
            result = gcd(result, j);
        }
        cout << result << endl;
    }
    return 0;
}
