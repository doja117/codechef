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
    for(int n, k; cin >> n >> k; ) {
        int g = 0;
        for(int a; n > 0; n--) {
            cin >> a;
            g = gcd(g, a);
        }
        string result = "YES\n";
        for(int i = 2; i * i <= g; i++) {
            while(g % i == 0) {
                if(i > k) {
                    result = "NO\n";
                }
                g /= i;
            }
        }
        if(g > k) {
            result = "NO\n";
        }
        cout << result;
    }
    return 0;
}
