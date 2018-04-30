#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; cout << endl) {
        int g = 0;
        for(int i = 0, a; i < n; i++) {
            cin >> a;
            g = gcd(g, a);
        }
        if(g == 1) {
            cout << n;
        } else {
            cout << -1;
        }
    }
    return 0;
}
