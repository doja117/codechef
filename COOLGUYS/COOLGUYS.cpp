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
    for(long long N; cin >> N; ) {
        long long top = 0, bottom = N * N;
        for(long long i = 1; i <= N; ) {
            auto nexti = N / (N / i) + 1;
            top += (N / i) * (nexti - i);
            i = nexti;
        }
        auto g = gcd(top, bottom);
        top /= g;
        bottom /= g;
        cout << top << '/' << bottom << endl;
    }
    return 0;
}
