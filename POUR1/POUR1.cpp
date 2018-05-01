#include <iostream>
using namespace std;

int solve(int a, int b, int c) {
    int result = 0;
    for(int A = 0, B = 0; A != c && B != c; result++) {
        if(B == b) {
            B = 0;
        } else if(A == 0) {
            A = a;
        } else {
            int m = min(A, b - B);
            A -= m;
            B += m;
        }
    }
    return result;
}

int gcd(int a, int b) {
    while(b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    for(int a, b, c; cin >> a >> b >> c; cout << endl) {
        if(c > max(a, b)) {
            cout << -1;
        } else if(c % gcd(a, b) == 0) {
            cout << min(solve(a, b, c), solve(b, a, c));
        } else {
            cout << -1;
        }
    }
    return 0;
}
