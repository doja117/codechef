#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(long long a, b, c; cin >> a >> b >> c && t--; cout << (abs(b + b - c - a) + 1) / 2 << endl) {
    }
    return 0;
}
