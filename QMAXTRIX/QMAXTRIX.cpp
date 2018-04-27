#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    int row[n], column[n + 1], sum = 0;
    fill(column, column + n, 0);
    pair<int, int> m[n];
    for(int i = 0, l, r; i < n; i++) {
        cin >> l >> r;
        m[i] = {l, r};
        row[i] = r - l + 1;
        sum += row[i];
        column[l - 1]++;
        column[r]--;
    }
    for(int i = 1; i < n; i++) {
        column[i] += column[i - 1];
    }
    cin >> q;
    for(int l, r; cin >> l >> r; ) {
        auto t = sum - row[l - 1] - column[r - 1];
        if(r >= m[l - 1].first && r <= m[l - 1].second) {
            t++;
        }
        if(t % 2 == 0) {
            cout << "E\n";
        } else {
            cout << "O\n";
        }
    }
    return 0;
}
