#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; cout << endl) {
        int x[n], y[n];
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        if(n % 2 == 1) {
            cout << 1;
        } else {
            sort(x, x + n);
            sort(y, y + n);
            cout << (long long)(x[n / 2] - x[n / 2 - 1] + 1) * (y[n / 2] - y[n / 2 - 1] + 1);
        }
    }
    return 0;
}
