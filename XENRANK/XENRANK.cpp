#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(long long u, v; cin >> u >> v; ) {
        cout << (u + v) * (u + v + 1) / 2 + u + 1 << endl;
    }
    return 0;
}
