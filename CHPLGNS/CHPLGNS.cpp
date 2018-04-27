#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; cout << endl) {
        pair<int, int> polygon[n];
        for(int i = 0; i < n; i++) {
            int m, x, y, maxx = INT_MIN;
            for(cin >> m; m > 0; m--) {
                cin >> x >> y;
                maxx = max(maxx, x);
            }
            polygon[i] = {maxx, i};
        }
        sort(polygon, polygon + n);
        int result[n];
        for(int i = 0; i < n; i++) {
            result[polygon[i].second] = i;
        }
        for(int i = 0; i < n; i++) {
            cout << result[i] << ' ';
        }
    }
    return 0;
}
