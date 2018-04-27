#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int n; cin >> n; cout << endl) {
        bool exist = true;
        vector<pair<int, int>> c, d;
        c.reserve(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int j;
            cin >> j;
            if(j == 0) {
                d.emplace_back(0, i);
            } else {
                c.emplace_back(j, i);
            }
            sum += j;
            if(j == n) {
                exist = false;
            }
        }
        c.insert(c.end(), d.begin(), d.end());
        if(sum != n) {
            exist = false;
        }
        if(exist) {
            int result[n];
            for(int i = 0, j = 1; i < n; i++) {
                for(int k = 1; k <= c[i].first; k++, j++) {
                    result[c[j % n].second] = c[i].second + 1;
                }
            }
            for(int i = 0; i < n; i++) {
                cout << result[i] << ' ';
            }
        } else {
            cout << -1;
        }
    }
    return 0;
}
