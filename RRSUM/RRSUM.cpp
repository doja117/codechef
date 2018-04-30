#include <iostream>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    for(long long q; cin >> q; ) {
        cout << max(min(q - n - 1, n) - max(1ll, q - n - n) + 1, 0ll) << endl;
    }
    return 0;
}
