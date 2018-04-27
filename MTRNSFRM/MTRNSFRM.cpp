#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n, m; cin >> n >> m; ) {
        long long a[n][m], b[n][m], c[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> b[i][j];
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        long long result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(c[i][j] + c[0][0] - c[i][0] - c[0][j] != 0) {
                    result = -1;
                }
            }
        }
        if(result != -1) {
            long long p[n + m];
            for(int i = 0; i < n; i++) {
                p[i] = c[i][0] - c[0][0];
            }
            for(int i = 0; i < m; i++) {
                p[i + n] = -c[0][i];
            }
            sort(p, p + n + m);
            long long x = p[(n + m) / 2];
            for(int i = 0; i < n + m; i++) {
                result += abs(p[i] - x);
            }
        }
        cout << result << endl;
    }
    return 0;
}
