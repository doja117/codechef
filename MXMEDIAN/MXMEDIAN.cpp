#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; cout << endl) {
        int a[2 * n];
        for(int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        sort(a, a + 2 * n);
        cout << a[n + n / 2] << endl;
        for(int i = 0; i < n; i++) {
            cout << a[i] << ' ' << a[i + n] << ' ';
        }
    }
    return 0;
}
