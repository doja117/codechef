#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, k; cin >> n >> k; cout << endl) {
        if(k == 1) {
            cout << 1;
            continue;
        }
        if(k <= n / 2) {
            for(int i = 2; i <= 2 * k; i += 2) {
                cout << i << ' ';
            }
        } else {
            cout << -1;
        }
    }
    return 0;
}
