#include <iostream>
using namespace std;

int main() {
    int n, m, l;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> l;
    long long e1 = 0, e2 = 0;
    bool b1 = false, b2 = false;
    for(int i, j; cin >> i >> j; ) {
        if(i <= n && j <= m) {
            e1 += a[i - 1][j - 1];
        } else {
            b1 = true;
        }
        if(i <= m && j <= n) {
            e2 += a[j - 1][i - 1];
        } else {
            b2 = true;
        }
    }
    if(b1) {
        e1 = -1;
    }
    if(b2) {
        e2 = -1;
    }
    cout << max(e1, e2);
    return 0;
}
