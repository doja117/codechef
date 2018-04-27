#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    b[0] = -1;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i - 1]) {
            b[i] = b[i - 1];
        } else {
            b[i] = i - 1;
        }
    }
    c[n - 1] = n;
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] == a[i + 1]) {
            c[i] = c[i + 1];
        } else {
            c[i] = i + 1;
        }
    }
    for(int l, r, k; cin >> l >> r >> k; cout << endl) {
        int mid = (l + r) / 2 - 1;
        if(min(c[mid], r) - max(b[mid], l - 2) - 1 >= k) {
            cout << a[mid];
        } else {
            cout << -1;
        }
    }
    return 0;
}
