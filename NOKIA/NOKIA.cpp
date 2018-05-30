#include <iostream>
using namespace std;

const int MAXN = 31;
int first[MAXN], last[MAXN];

int main() {
    int T;
    cin >> T;
    for(int i = 1; i < MAXN; i++) {
        first[i] = (i + 1) + first[i / 2] + first[i - 1 - i / 2];
        last[i] = i * (i + 3) / 2;
    }
    for(int n, m; cin >> n >> m; ) {
        if(m >= first[n]) {
            cout << max(m - last[n], 0) << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
