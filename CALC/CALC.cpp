#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long N, B; cin >> N >> B; ) {
        auto b1 = N / (2 * B), a1 = N - b1 * B;
        auto b2 = b1 + 1, a2 = N - b2 * B;
        cout << max(a1 * b1, a2 * b2) << endl;
    }
    return 0;
}
