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
    int T, a;
    cin >> T;
    for(string b; cin >> a >> b; ) {
        if(a == 0) {
            cout << b << endl;
            continue;
        }
        int r = 0;
        for(auto i : b) {
            r = (r * 10 + i - '0') % a;
        }
        cout << gcd(a, r) << endl;
    }
    return 0;
}
