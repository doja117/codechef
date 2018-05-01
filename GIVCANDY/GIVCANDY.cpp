#include <iostream>
using namespace std;
 
long long gcd(long long a, long long b) {
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
    for(long long A, B, C, D; cin >> A >> B >> C >> D; ) {
        auto g = gcd(C, D), r = abs(A - B) % g;
        cout << min(r, g - r) << endl;
    }
    return 0;
}
