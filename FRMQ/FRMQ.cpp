#include <iostream>
using namespace std;

int main() {
    int n, m, x, y;
    cin >> n;
    int log2[n + 1];
    for(int i = 0; ; i++) {
        for(int j = 1 << i; j < (1 << (i + 1)); j++) {
            if(j > n) {
                goto DONE;
            }
            log2[j] = i;
        }
    }
    DONE:
    int size = log2[n] + 1, table[size][n];
    for(int i = 0; i < n; i++) {
        cin >> table[0][i];
    }
    for(int j = 1; j < size; j++) {
        for(int i = 0; i <= n - (1 << j); i++) {
            table[j][i] = max(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
        }
    }
    long long result = 0;
    for(cin >> m >> x >> y; m > 0; m--) {
        int l = min(x, y), r = max(x, y), j = log2[r - l + 1];
        result += max(table[j][l], table[j][r - (1 << j) + 1]);
        x += 7;
        while(x >= n - 1) {
            x -= n - 1;
        }
        y += 11;
        while(y >= n) {
            y -= n;
        }
    }
    cout << result;
    return 0;
}
